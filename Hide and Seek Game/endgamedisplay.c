/*  # File:   endgamedisplay.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A module for to display an image for the end of game
*/

#include "system.h"
#include "ledmat.h"

/* This function displays bitmap[] for winner or loser */
void display_image(const uint8_t bitmap[])
{
    ledmat_display_column(bitmap[0], 0);
    ledmat_display_column(bitmap[1], 1);
    ledmat_display_column(bitmap[2], 2);
    ledmat_display_column(bitmap[3], 3);
    ledmat_display_column(bitmap[4], 4);
}
