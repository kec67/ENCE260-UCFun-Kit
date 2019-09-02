/*  # File:   gamestart.h
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
 * The first player will begin the game as the hider.
 */
_Bool displayWelcome(void);

/* Function to begin game.
 * Returns the value of isHider. Value of 1 for the hider and 0 for the seeker
 */
_Bool begin_game(void);

