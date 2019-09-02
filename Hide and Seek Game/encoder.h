/*  # File:   encoder.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A module to keep sending and receiving player position for the game
*/

#include "movement.h"

/* Function to code value for position */
char encodePos (int position[]);

/* Function to decode value for position */
void decodePos (int position[], char encodedVal);

