/*  # File:   comparison.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A comparison module for the game. Consists of functions to check if seeker is close to the hider
*/

#include "movement.h"

#define upDirection -1
#define downDirection +1
#define leftDirection -1
#define rightDirection +1

/* if equal
 * returns 1 if positions are equal
 */
_Bool same_spot(int position1[], int position2[])
{
    _Bool sameSpot = 0;
    if (position1[columnNum] == position2[columnNum] && position1[rowNum] == position2[rowNum]) {
        sameSpot = 1;
    }
    return sameSpot;
}


/* is to the west
 * returns 1 if the hider is to the left of the seeker
 */
_Bool to_the_west(int position1[], int position2[])
{
    _Bool isWest = 0;
    if (position1[columnNum] == (position2[columnNum] + leftDirection) && position1[rowNum] == position2[rowNum]) {
        isWest = 1;
    }
    return isWest;
}


/* is to the east
 * returns 1 if the hider is to the right of the seeker
 */
_Bool to_the_east(int position1[], int position2[])
{
    _Bool isEast = 0;
    if (position1[columnNum] == (position2[columnNum] + rightDirection) && position1[rowNum] == position2[rowNum]) {
        isEast = 1;
    }
    return isEast;
}

/* is to the north
 * returns 1 if the hider is to the north of the seeker
 */
_Bool to_the_north(int position1[], int position2[])
{
    _Bool isNorth = 0;
    if (position1[columnNum] == (position2[columnNum]) && position1[rowNum] == position2[rowNum] + upDirection) {
        isNorth = 1;
    }
    return isNorth;
}

/* is to the south
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_south(int position1[], int position2[])
{
    _Bool isSouth = 0;
    if (position1[columnNum] == (position2[columnNum]) && position1[rowNum] == position2[rowNum] + downDirection) {
        isSouth = 1;
    }
    return isSouth;
}

/* is to the north west
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_north_west(int position1[], int position2[])
{
    _Bool isNorthWest = 0;
    if (position1[columnNum] == (position2[columnNum] + leftDirection) && position1[rowNum] == position2[rowNum] + upDirection) {
        isNorthWest = 1;
    }
    return isNorthWest;
}

/* is to the north east
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_north_east(int position1[], int position2[])
{
    _Bool isNorthEast = 0;
    if (position1[columnNum] == (position2[columnNum] + rightDirection) && position1[rowNum] == position2[rowNum] + upDirection) {
        isNorthEast = 1;
    }
    return isNorthEast;
}

/* is to the south west
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_south_west(int position1[], int position2[])
{
    _Bool isSouthWest = 0;
    if (position1[columnNum] == (position2[columnNum] + leftDirection) && position1[rowNum] == position2[rowNum] + downDirection) {
        isSouthWest = 1;
    }
    return isSouthWest;
}

/* is to the south east
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_south_east(int position1[], int position2[])
{
    _Bool isSouthEast = 0;
    if (position1[columnNum] == (position2[columnNum] + rightDirection) && position1[rowNum] == position2[rowNum] + downDirection) {
        isSouthEast = 1;
    }
    return isSouthEast;
}


//compare
/* it looks if it's either equal or next to
 * runs to the left
 * runs to the north
 * runs to the right
 * runs to the south
 * runs to the north left
 * runs to the north right
 * runs to the south left
 * runs to the south right
 * 
 * returns true if the position 1 is within 1 pixel of position 2
 */
_Bool players_are_close(int position1[], int position2[])
{
    _Bool isClose = 0;

    if (to_the_west(position1, position2)) {
        isClose = 1;
    } else if (to_the_east(position1, position2)) {
        isClose = 1;
    } else if (to_the_north(position1, position2)) {
        isClose = 1;
    } else if (to_the_south(position1, position2)) {
        isClose = 1;
    } else if (to_the_north_west(position1, position2)) {
        isClose = 1;
    } else if (to_the_north_east(position1, position2)) {
        isClose = 1;
    } else if (to_the_south_west(position1, position2)) {
        isClose = 1;
    } else if (to_the_south_east(position1, position2)) {
        isClose = 1;
    }

    return isClose;
}
