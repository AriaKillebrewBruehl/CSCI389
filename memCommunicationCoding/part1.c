#include "part1.h"

// Helper function to generate a random array of unsigned ints.
uint32_t* random_array(uint32_t buff_size, uint32_t tests) {
    uint32_t* randoms = (uint32_t*)malloc(sizeof(uint32_t)*tests);
    for (uint32_t i =0; i < tests; i++) {
        randoms[i] =  (uint32_t)(rand() % (buff_size - 1));
    }
    return randoms;
}

void run_tests(uint32_t buff_begin, uint32_t buff_end, uint32_t tests) {
    srand((unsigned) time(NULL));
    uint32_t buff_size = buff_begin;
    // calculate the approximate number of iterations
    uint32_t  full_iters = (uint32_t)log10((buff_end) - (buff_begin));
    uint32_t NUM_ITERS = 10 * full_iters;

    // file to store output for graphing purposes
    FILE * output;
    output = fopen ("output.txt" , "w+");

    for (uint32_t i = 0; i < NUM_ITERS; i++) {
        // allocate an array of chars
        char* array = (char*)malloc(sizeof(char) * buff_size);
        //generate list of random indices to pull from
        uint32_t* random_indices = random_array(buff_size, tests);
        volatile char c = 0;

        // time memory accesses
        struct timespec start, stop;
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (uint32_t j = 0; j < tests; j++) {
            c = array[random_indices[j]];
        }
        clock_gettime(CLOCK_MONOTONIC, &stop);

        // calculate time taken
        double time_taken;
        time_taken = (stop.tv_sec *1e9 + stop.tv_nsec) - (start.tv_sec * 1e9 + start.tv_nsec);
        double avg_time;
        avg_time = time_taken / (double)tests;

        printf("%9d | %8.5fns\n",buff_size,avg_time);

        // save output to file
        fprintf(output, "(%d, %f), ", (uint32_t)buff_size, avg_time);

        // increment buff_size (Will showed me this trick!)
        uint32_t base = (uint32_t)log10(buff_size);
        buff_size += (uint32_t)pow(10,base)/2;

        free(array);
        free(random_indices);
    }

    fclose(output);
}

int main(void) {
    printf("----------------------\n");
    printf("%9s | %8s\n", "buff_size", "avg_time");
    run_tests(5e3, 5e7, 1e8);
    printf("----------------------\n");

    return 0;
}
