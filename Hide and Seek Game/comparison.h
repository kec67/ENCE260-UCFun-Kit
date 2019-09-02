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
_Bool same_spot(int position1[], int position2[]);

/* is to the west
 * returns 1 if the hider is to the left of the seeker
 */
_Bool to_the_west(int position1[], int position2[]);

/* is to the east
 * returns 1 if the hider is to the right of the seeker
 */
_Bool to_the_east(int position1[], int position2[]);

/* is to the north
 * returns 1 if the hider is to the north of the seeker
 */
_Bool to_the_north(int position1[], int position2[]);

/* is to the south
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_south(int position1[], int position2[]);

/* is to the north west
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_north_west(int position1[], int position2[]);

/* is to the north east
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_north_east(int position1[], int position2[]);

/* is to the south west
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_south_west(int position1[], int position2[]);

/* is to the south east
 * returns 1 if the hider is to the south of the seeker
 */
_Bool to_the_south_east(int position1[], int position2[]);


//compare
/* it looks if it's either equal or next to
 * runs to the left - edits external variable
 * runs to the north - edits external variable
 * runs to the right - edits external variable
 * runs to the south - edits external variable
 * runs to the north left
 * runs to the north right
 * runs to the south left
 * runs to the south right
 */


_Bool players_are_close(int position1[], int position2[]);
