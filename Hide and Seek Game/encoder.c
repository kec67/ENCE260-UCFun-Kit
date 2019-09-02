/*  # File:   encoder.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A module to keep sending and receiving player position for the game
*/

#include "movement.h"

/* Function to code value for position */
char encodePos (int position[])
{
    int encodedNum = position[columnNum] * 10 + position[rowNum];
    char encodedVal = 'I' + encodedNum;
    return encodedVal;
}

/* Function to decode value for position */
void decodePos (int position[], char encodedVal)
{
    int encodedNum = encodedVal - 'I';
    position[columnNum] = (encodedNum - encodedNum % 10)/10;
    position[rowNum] = encodedNum % 10;
}
