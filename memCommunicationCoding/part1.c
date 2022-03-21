#include "part1.h"

uint32_t* random_array(uint32_t buff_size, uint32_t sub_iters) {
    uint32_t* randoms = (uint32_t*)malloc(sizeof(uint32_t)*sub_iters);
    for (int i =0; i < sub_iters; i++) {
        randoms[i] =  (uint32_t)(rand() % (buff_size - 1));
    }
    return randoms;
}


// double get_average_time(uint32_t buff_size, uint32_t iters, uint32_t sub_iters) {


//     //char* array = (char*)malloc(sizeof(char) * buff_size);          // create char array of size biff_size
//     char* array = random_char_array(buff_size);
//     uint32_t* random_indices = random_array(buff_size, sub_iters);  // create array of ranodm indices to access

//     double total_time = 0;
//     volatile char c;

//     for (int i = 0; i < iters; i++) {
//         struct timespec start, stop; // initialize clock

//         clock_gettime(CLOCK_MONOTONIC, &start);
//         for (int j = 0; j < sub_iters; j++) {
//             c = array[random_indices[j]];
//         }
//         clock_gettime(CLOCK_MONOTONIC, &stop);

//         struct timespec dif = diff(start, stop);
//         double time_taken = dif.tv_nsec / sub_iters;

//         total_time += time_taken;
//     }

//     double avg_time = total_time / iters;

//     free(array);
//     free(random_indices);

//     return avg_time;
// }

int main(void) {
    srand((unsigned) time(NULL));
    uint32_t buff_size = 5000;
    uint32_t sub_iters = 100000000;


    FILE * output;
    output = fopen ("output.txt" , "w+");

    for (int i = 0; i < 50; i++) {
        char* array = (char*)malloc(sizeof(char) * buff_size);
        uint32_t* random_indices = random_array(buff_size, sub_iters);
        volatile char c = 0;

        struct timespec start, stop;
        clock_gettime(CLOCK_MONOTONIC, &start);
        for (int j = 0; j < sub_iters; j++) {
            c = array[random_indices[j]];
        }
        clock_gettime(CLOCK_MONOTONIC, &stop);


        double time_taken = (stop.tv_sec *1e9 + stop.tv_nsec) - (start.tv_sec * 1e9 + start.tv_nsec);
        double avg_time = time_taken / (double)sub_iters;

        printf("%8d | %8.5fns\n",buff_size,avg_time);

        fprintf(output, "(%d, %f), \n", (uint32_t)buff_size, avg_time);

        uint32_t base = (uint32_t)log10(buff_size);
        buff_size += (uint32_t)pow(10,base/2);
        free(array);
        free(random_indices);
    }

    fclose(output);

    return 0;
}