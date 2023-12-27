#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
//#include <ncurses.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

const int MAX_OBJECTS=500;
const int NUM_INTERATIONS=50000;
const int MAX_SIZE=500;
const int MIN_SIZE=50;

struct allocation {
    void *block;
    size_t size;
    bool valid;
};

void do_lots_of_allocations(){
    struct allocation allocs[MAX_OBJECTS];

    // initially no allocated objects
    for (int i=0; i < MAX_OBJECTS; i++){
        allocs[i].valid = false;
    }

for (int i=0; i < NUM_INTERATIONS; i++){
    int ridx = rand() % MAX_OBJECTS;
    size_t rsize = MIN_SIZE + (rand() % (MAX_SIZE-MIN_SIZE));

    if (allocs[ridx].valid) {
        free(allocs[ridx].block);
        allocs[ridx].valid = false;
    } else {
        allocs[ridx].block = malloc(rsize);
        allocs[ridx].size = rsize;
        allocs[ridx].valid = true;
    }
    }
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    do_lots_of_allocations();
    return EXIT_SUCCESS;
}
