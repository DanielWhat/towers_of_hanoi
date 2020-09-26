/* Author: Daniel Watt 
 * Description: Series of functions to help with a Tower of Hanoi implementation. In this
 * implementation a tower should be depicted as a list of ints, for example:
 * [123, 0, 0] where 1 is the smallest block, 2 is the second smallest block, etc. */

#ifndef TOWERS_OF_HANOI_FUNC
#define TOWERS_OF_HANOI_FUNC

#include <math.h>

int get_number_of_blocks(int tower);
    /* Returns the number of blocks in a tower (e.g. 245 returns 3, 0 returns 0 etc.) */



int get_top_block(int tower);
    /* Takes a single tower (e.g. 249) and returns the top block (i.e. 2) */



int add_block_to_tower(int tower, int block);
    /* Takes a tower (e.g. 234) and a block (e.g. 1) and returns the resulting tower
     * (e.g. 1234). Does NOT check for the correctness of the operation! */



int remove_block_from_tower(int tower);
    /* Takes a tower, removes the top block, and returns the resulting tower */


#endif /* TOWERS_OF_HANOI_FUNC */
