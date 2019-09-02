/*  # File:   signals.c
    # Author: Anna-Kay Cressy, Kelly Esther Ling Ing Chan
    # Date:   17 Oct 2018
    # Descr:  A module for transmitting and receiving a character for the game
*/

#include "system.h"
#include "ir_uart.h"

/* Function to write character to IR_UART.*/
void send_signal(char character);

/* If there is a character ready to be read, read character from IR_UART.
 * This blocks if nothing is available to read.
 */
void signal_update(char* character);
