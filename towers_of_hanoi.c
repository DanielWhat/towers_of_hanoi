#include <stdio.h>
#include <math.h>
#include <stdbool.h>


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



bool move(int* towers, int current_index, int new_index) {
    /* Moves the top block from current_index to new_index. If the move is allowed, 
     * will carry out the move on the given list and return true. If the move is 
     * not allowed will return False and leave the towers untouched. */

    if (towers[current_index] == 0) {
        return true; //don't need to do anything to move from an index with 0 blocks
    }
    int top_block = get_top_block(towers[current_index]);
    //check the move is legal
    if (get_top_block(towers[new_index]) > top_block || get_top_block(towers[new_index]) == 0) {
        //carry out the move
        towers[new_index] = add_block_to_tower(towers[new_index], top_block); //add the block to the new tower
        towers[current_index] = remove_block_from_tower(towers[current_index]); //remove the top block from the old tower
        return true;
    } else {
        return false;
    }
}

int main () {
    int towers[] = {123, 0, 0}; //we reprisent blocks with numbers, 0 means no block, 1 is the smallest block etc.
    move(towers, 0, 2);
    printf("{%d, %d, %d}", towers[0], towers[1], towers[2]);
    return 0;
}
