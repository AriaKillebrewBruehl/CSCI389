#include "update_locations.h"

// Create a list of 'size' floating point numbers in the range [-bound, bound]
float * generate_random_list(int size, int bound) {
    static float* array;
    array = (float*)malloc(size *sizeof(int));

    for (int i = 0; i < size; i++) {
        float num = (float)rand();
        array[i] = num;
    }

    return array;
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
         fprintf(stderr, "Required arguments: vector_length(N) and iterations_num(M)");
        return -1;
    }
    int size = *argv[1];
    int iters = *argv[2];
    srand(size);
    float * xs = generate_random_list(size, 1000);
    float * ys = generate_random_list(size, 1000);
    float * zs = generate_random_list(size, 1000);
    float * vx = generate_random_list(size, 1);
    float * vy = generate_random_list(size, 1);
    float * vz = generate_random_list(size, 1);
}
