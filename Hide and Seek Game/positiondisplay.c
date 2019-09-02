/*  # File:   positiondisplay.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A module to display the position of players for the game.
*/

#include "display.h"

#define lightOn 1
#define lightOff 0
#define columnNum 0
#define rowNum 1

/* Function to turn on display */
void displayPlayer(int position[])
{
    display_pixel_set(position[columnNum], position[rowNum], lightOn);
}

/* Function to turn off display */
void undisplayPlayer(int position[])
{
    display_pixel_set(position[columnNum], position[rowNum], lightOff);
}
