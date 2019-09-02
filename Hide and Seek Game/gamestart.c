/*  # File:   gamestart.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A game start module for the Hide and Seek game.
*/

#include "system.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "pacer.h"
#include "navswitch.h"
#include "ir_uart.h"
#include "led.h"
#include "signals.h"

#define MESSAGE_RATE 10
#define LOOP_RATE 1500
#define PACER_RATE 1500

/* Function that displays the title of the game.
 * Gives an instruction for the first player to push down the navswitch stick.
 * The first player will begin the game as the hider. Returns true if the player
 * is the hider.
 */
_Bool displayWelcome(void)
{
    tinygl_init (LOOP_RATE);
    tinygl_font_set (&font5x7_1);
    tinygl_text_speed_set (MESSAGE_RATE);
    tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
    tinygl_text("Hide & seek! Push stick to hide");
    tinygl_update();
    ir_uart_init();
    pacer_init (PACER_RATE);

    char character = 'B';
    char startSignal = 'Z';

    _Bool isHider = 0;
    _Bool player_type_selected = 0;

    while(player_type_selected == 0) {

        navswitch_update();
        pacer_wait();
        tinygl_update();

        signal_update(&character);
        if (character == startSignal) {
            player_type_selected = 1;
            isHider = 0;
        }

        if (navswitch_push_event_p(NAVSWITCH_PUSH)) {
            player_type_selected = 1;
            isHider = 1;
            send_signal(startSignal);
        }
    }
    return isHider;
}

/* Function to begin game.
 * Returns the value of isHider and runs the game start sequence
 * Value of 1 for the hider and 0 for the seeker
 */

_Bool begin_game(void)
{
    _Bool isHider = displayWelcome();
    led_set (LED1, 0);
    return isHider;
}
