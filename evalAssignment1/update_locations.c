#include "update_locations.h"

int * generate_random_list(int size, int bound) {
    static int* array;
    array = (int*)malloc(size *sizeof(int));

    for (int i = 0; i < size; i++) {
        int num = rand();
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
    int * xs = generate_random_list(size, 1000);
    int * ys = generate_random_list(size, 1000);
    int * zs = generate_random_list(size, 1000);
    int * vx = generate_random_list(size, 1);
    int * vy = generate_random_list(size, 1);
    int * vz = generate_random_list(size, 1);
}
