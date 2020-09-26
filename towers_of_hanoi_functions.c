/* Author: Daniel Watt 
 * Description: Series of functions to help with a Tower of Hanoi implementation. In this
 * implementation a tower should be depicted as a list of ints, for example:
 * [123, 0, 0] where 1 is the smallest block, 2 is the second smallest block, etc. */
 
#include "towers_of_hanoi_functions.h"

int get_number_of_blocks(int tower) {
    /* Returns the number of blocks in a tower (e.g. 245 returns 3, 0 returns 0 etc.) */
    if (tower == 0) {
        return 0;
    } else {
        return (int)log10(tower) + 1;
    }
}



int get_top_block(int tower) {
    /* Takes a single tower (e.g. 249) and returns the top block (i.e. 2) */

    int number_of_blocks = get_number_of_blocks(tower); //get the number of blocks
    if (number_of_blocks == 0) {
        return 0;
    } else {
        int top_block = tower / ((int)pow(10, number_of_blocks - 1)); //get the top block
        return top_block;
    }
}



int add_block_to_tower(int tower, int block) {
    /* Takes a tower (e.g. 234) and a block (e.g. 1) and returns the resulting tower
     * (e.g. 1234). Does NOT check for the correctness of the operation! */

    int number_of_blocks = get_number_of_blocks(tower);
    int conversion_factor = (int)pow(10, number_of_blocks); //no -1 this time because we want to elavate the block to the next power of 10 so it can be added
    int new_tower = block * conversion_factor + tower;
    return new_tower;
}



int remove_block_from_tower(int tower) {
    /* Takes a tower, removes the top block, and returns the resulting tower */

    int number_of_blocks = get_number_of_blocks(tower);
    int new_tower = tower % (int)pow(10, number_of_blocks - 1);
    return new_tower;
}
