#include "update_locations.h"

// Create a list of 'size' int64_ting point numbers in the range [-bound, bound]
int64_t * generate_random_list(int32_t size, int32_t bound) {
    int64_t* array;
    array = (int64_t*)malloc(sizeof(int64_t) * size);


    for (int i = 0; i < size; i++) {
        int64_t num = (int64_t)(rand() % (2*bound+1)) - bound;
        array[i] = num;
    }
    return array;
}

// Update position by velocity, one time-step
void update_coords(int64_t * xs, int64_t * ys, int64_t * zs, int64_t * vx, int64_t * vy, int64_t * vz, int32_t size){
    for (int i = 0; i < size; i ++) {
        xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
    }
}

int64_t sum(int64_t * array, int32_t size) {
    int64_t sum = 0;
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
    int64_t * xs = generate_random_list(size, 1000);
    int64_t * ys = generate_random_list(size, 1000);
    int64_t * zs = generate_random_list(size, 1000);
    int64_t * vx = generate_random_list(size, 1);
    int64_t * vy = generate_random_list(size, 1);
    int64_t * vz = generate_random_list(size, 1);

    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i=0; i < iters; i++) {
        update_coords(xs, ys, zs, vx, vy, vz, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);
    int64_t chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
    double obj_count = (double)size*(double)iters;
    double time_taken;
    time_taken = ((double)stop.tv_sec - (double)start.tv_sec) * 1e9;
    time_taken = ((double)time_taken + ((double)stop.tv_nsec - start.tv_nsec)) * 1e-9;
    time_taken = time_taken * 1e6 / obj_count;
    printf("%fus\n",time_taken);
    printf("Final checksum is: %lld", chksum);

    free(xs);
    free(ys);
    free(zs);
    free(vx);
    free(vy);
    free(vz);
}
