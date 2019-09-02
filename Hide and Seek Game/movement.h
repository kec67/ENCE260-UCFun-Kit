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

/* Function that moves a character when the navswitch is toggled
 * returns true if the player moves */

void movePlayer(int position[]);

_Bool movePlayerOneSpace(int position[]);
