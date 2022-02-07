#include "update_locations.h"

// Create a list of 'size' int8_ting point numbers in the range [-bound, bound]
int8_t * generate_random_list(int32_t size, int32_t bound) {
    int8_t* array;
    array = (int8_t*)malloc(sizeof(int8_t) * size);


    for (int i = 0; i < size; i++) {
        int8_t num = (int8_t)(rand() % (2*bound+1)) - bound;
        array[i] = num;
    }
    return array;
}

// Update position by velocity, one time-step
void update_coords(int8_t * xs, int8_t * ys, int8_t * zs, int8_t * vx, int8_t * vy, int8_t * vz, int32_t size){
    for (int i = 0; i < size; i ++) {
        xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
    }
}

int8_t sum(int8_t * array, int32_t size) {
    int8_t sum = 0;
    for (int i = 0; i < size; i++) { sum += array[i];}
    return sum;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Required arguments: vector_length(N) and iterations_num(M)");
        return -1;
    }

    int32_t size = atoi(argv[1]);
    int32_t iters = atoi(argv[2]);
    srand(size);
    int8_t * xs = generate_random_list(size, 1000);
    int8_t * ys = generate_random_list(size, 1000);
    int8_t * zs = generate_random_list(size, 1000);
    int8_t * vx = generate_random_list(size, 1);
    int8_t * vy = generate_random_list(size, 1);
    int8_t * vz = generate_random_list(size, 1);

    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i=0; i < iters; i++) {
        update_coords(xs, ys, zs, vx, vy, vz, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);
    int8_t chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
    double obj_count = (double)size*(double)iters;
    double time_taken;
    time_taken = ((double)stop.tv_sec - (double)start.tv_sec) * 1e9;
    time_taken = ((double)time_taken + ((double)stop.tv_nsec - start.tv_nsec)) * 1e-9;
    time_taken = time_taken * 1e6 / obj_count;
    printf("%fus\n",time_taken);
    printf("Final checksum is: %f", chksum);

    free(xs);
    free(ys);
    free(zs);
    free(vx);
    free(vy);
    free(vz);
}
