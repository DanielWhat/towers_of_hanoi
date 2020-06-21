#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>


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

    if (towers[current_index] == 0 || current_index == new_index) {
        return true; //don't need to do anything to move from an index with 0 blocks, or to move from 1 index to itself
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


bool move_n(int* towers, int n, int start_index, int via_index, int end_index) {
    /* Moves n blocks from the start_index to the end_index via the via_index 
     * Returns true if the operation was successful, false otherwise. As the 
     * function does operations it will print the towers and list the moves it 
     * makes. */
    if (n == 1) {
        printf("%d -> %d\n", start_index, end_index);
        return move(towers, start_index, end_index);
    } 
    bool res1 = move_n(towers, n-1, start_index, end_index, via_index);
    printf("{%d, %d, %d}\n", towers[0], towers[1], towers[2]);

    printf("%d -> %d\n", start_index, end_index);
    bool res2 = move(towers, start_index, end_index);
    printf("{%d, %d, %d}\n", towers[0], towers[1], towers[2]);

    bool res3 = move_n(towers, n-1, via_index, start_index, end_index);
    return res1 && res2 && res3;
}


bool init_towers(int towers[], int n, char* argv[]) {
    // assign user input to tower
    for (int i = 0; i < n; i++) {
        towers[i] = atoi(argv[i+1]); 
    }
    //now check that the tower is valid (i.e. 1st block < 2nd block < 3rd block etc.)
    int top;
    int bottom;
    for (int i = 0; i < n; i++) {
        for (int j = get_number_of_blocks(towers[i]); j > 1; j--) {
            top = get_top_block(towers[i] % (int)pow(10, j));
            bottom = get_top_block(towers[i] % (int)pow(10, j - 1));
            if (top >= bottom) {
                printf("Error: Tower %d has a %d on top of a %d, this is invalid.", i, top, bottom);
                return false;
            }
        }
    }
    return true;
}


int main (int argc, char* argv[]) {
    if (argc != 4) {
        printf("Error: Expecting 3 arguments to be supplied. Instead %d arguments were supplied.", argc);
        return 1;
    }
    int towers[] = {1234, 0, 0}; //we reprisent blocks with numbers, 0 means no block, 1 is the smallest block etc.
    if (!init_towers(towers, 3, argv)) { //init towers will return false if there are errors
        return 2;
    }

    //start solving problem
    printf("{%d, %d, %d}\n", towers[0], towers[1], towers[2]);
    bool is_success = move_n(towers, get_number_of_blocks(towers[0]), 0, 1, 2);
    if (is_success) {
        printf("{%d, %d, %d}\n", towers[0], towers[1], towers[2]);
    } 
    return 0;
}
