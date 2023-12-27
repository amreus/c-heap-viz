#include <stdlib.h>
#include <math.h>
#include <time.h>

const int NUM_ITERATIONS=500;
const int BATCH_SIZE=100;
const int MAX_SIZE=500;
const int MIN_SIZE=50;


void leaky_function(){
    void *p1 = malloc(MIN_SIZE + (rand() % (MAX_SIZE-MIN_SIZE)));
    // void *p2 = malloc(MIN_SIZE + (rand() % (MAX_SIZE-MIN_SIZE)));
    void *p3 = malloc(MIN_SIZE + (rand() % (MAX_SIZE-MIN_SIZE)));

    free(p3);
    // free(p2);
    free(p1);

}


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    for (int i=0; i < NUM_ITERATIONS; i++){
        leaky_function();
    }

    return EXIT_SUCCESS;
}
