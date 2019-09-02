/*  # File:   movement.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A module to move players for the game
*/

#include "navswitch.h"

#define columnNum 0
#define rowNum 1
#define right_edge 4
#define left_edge 0
#define top_edge 0
#define bottom_edge 6

/* Function that moves a character when the navswitch is toggled */

void movePlayer(int position[])
{
    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        if (position[columnNum] < right_edge) {
            position[columnNum]++;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        if (position[columnNum] > left_edge) {
            position[columnNum]--;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
        if (position[rowNum] > top_edge) {
            position[rowNum]--;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        if (position[rowNum] < bottom_edge) {
            position[rowNum]++;
        }
    }

}

/* Function to move hider by one space after hider has moved for the first round 
 * returns true if the player moves */
_Bool movePlayerOneSpace(int position[])
{
    _Bool hasMoved = 0;

    if (navswitch_push_event_p(NAVSWITCH_EAST)) {
        if (position[columnNum] < right_edge) {
            position[columnNum]++;
            hasMoved = 1;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_WEST)) {
        if (position[columnNum] > left_edge) {
            position[columnNum]--;
            hasMoved = 1;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_NORTH)) {
        if (position[rowNum] > top_edge) {
            position[rowNum]--;
            hasMoved = 1;
        }
    } else if (navswitch_push_event_p(NAVSWITCH_SOUTH)) {
        if (position[rowNum] < bottom_edge) {
            position[rowNum]++;
            hasMoved = 1;
        }
    }

    return hasMoved;
}
