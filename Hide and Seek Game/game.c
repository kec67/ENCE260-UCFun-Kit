/*  # File:   game.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:* A simple game of hide and seek. Seeker tries to find the hider.
            * Seeker will be given a clue if the hider is close.
            * Hider is able to see the seeker at all times but can only move one spot after the first hide.
*/


#include "system.h"
#include "pacer.h"
#include "display.h"
#include "navswitch.h"
#include <avr/io.h>
#include "led.h"
#include "ledmat.h"
#include "gamestart.h"
#include "signals.h"
#include "encoder.h"
#include "comparison.h"
#include "endgamedisplay.h"
#include "movement.h"
#include "positiondisplay.h"

#define MESSAGE_RATE 10
#define LOOP_RATE 1500
#define PACER_RATE 1500

/* Define image for winner with a happy face */
static const uint8_t win[] = {0x30, 0x46, 0x40, 0x46, 0x30};

/* Define image for loser with a sad face */
static const uint8_t lose[] = {0x60, 0x16, 0x10, 0x16, 0x60};


int main(void)
{
    system_init();
    pacer_init(PACER_RATE);
    display_init();
    navswitch_init();
    led_init ();

    /* sets inital conditions */

    _Bool hasMoved = 0;
    char defaultCharacter = 'H';
    char character = defaultCharacter;
    char hiderWinSignal = 'A';
    char seekerWinSignal = 'B';
    char nextRoundSignal = 'C';
    
    int currentPos[2] = {0,0};
    int otherPlayerPos[2] = {0,0};
    int pacercount = 0;
    int playerWon = 0;
    int roundNum = 0;
    _Bool endGame = 0;

    /*Starts the game */
    _Bool isHider = begin_game();
    display_clear();

    while (endGame == 0) {
        pacer_wait ();

        /* For the hider*/
        if (isHider) {
            
            // update navswitch
            if (pacercount % 75 == 0) {
                navswitch_update();
            }
            
            // turns on light if player's turn, off if not
            if (roundNum % 2 == 0) {
                led_set (LED1, 1);
            } else {
                led_set (LED1, 0);
            }
            
            //if it's the first round, run movePlayer otherwise only allow the hider to move 1 space on their turn
            if (pacercount % 75 == 0 && roundNum == 0) {
                undisplayPlayer(currentPos);
                movePlayer(currentPos);
            }  else if (pacercount % 75 == 0 && roundNum % 2 == 0 && hasMoved == 0 && roundNum > 0) {
                undisplayPlayer(currentPos);
                hasMoved = movePlayerOneSpace(currentPos);
            }
            
            //updates signal
            signal_update(&character);
            
            //checks for end game signals from other player
            if (character == seekerWinSignal) {
                endGame = 1;
            } else if (character == hiderWinSignal) {
                playerWon = 1;
                endGame = 1;
            }

            //if it receieves a position signal, decodes it and resets the character variable
            if (character != defaultCharacter && character >= defaultCharacter) {
                undisplayPlayer(otherPlayerPos);
                decodePos(otherPlayerPos, character);
                character = defaultCharacter;
            } else if (character == nextRoundSignal) {
                roundNum++;
                character = defaultCharacter;
            }

            //sends players position to other player when navswitch is pushed and checks for an endgame
            if (pacercount % 75 == 0 && navswitch_push_event_p(NAVSWITCH_PUSH) && roundNum % 2 == 0) {
                send_signal(encodePos(currentPos));
                roundNum++;
                hasMoved = 0;

                if (same_spot(currentPos, otherPlayerPos)) {
                    send_signal(seekerWinSignal);
                    endGame = 1;
                }
            }

            //makes the other player flash
            if (pacercount % 150 == 0) {
                undisplayPlayer(otherPlayerPos);
            } else if (pacercount % 75 == 1) {
                displayPlayer(otherPlayerPos);
            }

            //updates player position
            display_update();
            displayPlayer(currentPos);
            display_update();

        /* For the seeker */
        } else if (isHider == 0) {
            
            // update navswitch
            if (pacercount % 75 == 0) {
                navswitch_update();
            }

            // turns on light if player's turn, off if not
            if (roundNum % 2 == 1) {
                led_set (LED1, 1);
            } else {
                led_set (LED1, 0);
            }

            //if it's the player's turn, allow them to move
            if (pacercount % 75 == 0 && roundNum % 2 == 1) {
                undisplayPlayer(currentPos);
                movePlayer(currentPos);
                send_signal(encodePos(currentPos));
            }

            //updates signal
            signal_update(&character);
            
            
            //checks for endgame signals from the other player
            if (character == hiderWinSignal) {
                endGame = 1;
            }

            if (character == seekerWinSignal) {
                playerWon = 1;
                endGame = 1;
            }

            //decodes a position signal from the other player
            if (character != defaultCharacter && character >= defaultCharacter) {
                undisplayPlayer(otherPlayerPos);
                decodePos(otherPlayerPos, character);
                roundNum++;
                character = defaultCharacter;
            }

            //ends player's round when navswitch is pushed, sends signal to other player and checks to see if anyone has won
            if (pacercount % 75 == 0 && navswitch_push_event_p(NAVSWITCH_PUSH) && roundNum % 2 == 1) {
                roundNum++;
                send_signal(nextRoundSignal);
                if (same_spot(currentPos, otherPlayerPos)) {
                    playerWon = 1;
                    send_signal(seekerWinSignal);
                    endGame = 1;
                } else if (roundNum > 10) {
                    send_signal(hiderWinSignal);
                    endGame = 1;
                }
            }

            //displayers the hider when it is not the seeker's turn if the seeker is 1 pixel away from the hider
            if (players_are_close(currentPos, otherPlayerPos) && roundNum % 2 == 0) {
                if (pacercount % 500 == 0) {
                    undisplayPlayer(otherPlayerPos);
                } else if (pacercount % 250 == 0) {
                    displayPlayer(otherPlayerPos);
                }
            }

            //updates the player display
            displayPlayer(currentPos);
            display_update();
        }

        pacercount++;
    }

    display_clear();
    display_update();

    while(1) {
        /* The player that won will receive a happy face display while the loser gets a sad face display */
        if (playerWon) {
            led_set (LED1, 1);
            display_image(win);
        } else {
            led_set (LED1, 0);
            display_image(lose);
        }
    }
}

