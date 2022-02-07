#include "update_locations.h"

// Create a list of 'size' floating point numbers in the range [-bound, bound]
float * generate_random_list(int32_t size, int32_t bound) {
    float* array;
    array = (float*)malloc(size);


    for (int i = 0; i < size; i++) {
        float num = (float)(rand() % (2*bound+1)) - bound;
        array[i] = num;
    }

    return array;
}

// Update position by velocity, one time-step
void update_coords(float * xs, float * ys, float * zs, float * vx, float * vy, float * vz, int32_t size){
    for (int i = 0; i < size; i ++) {
        xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
    }
}

float sum(float * array, int32_t size) {
    float sum = 0;
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
    float * xs = generate_random_list(size, 1000);
    float * ys = generate_random_list(size, 1000);
    float * zs = generate_random_list(size, 1000);
    float * vx = generate_random_list(size, 1);
    float * vy = generate_random_list(size, 1);
    float * vz = generate_random_list(size, 1);

    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i=0; i < iters; i++) {
        update_coords(xs, ys, zs, vx, vy, vz, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);
    float chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
    double obj_count = (double)size*(double)iters;
    double time_taken;
    time_taken = (stop.tv_sec - start.tv_sec) * 1e9;
    time_taken = (time_taken + (stop.tv_nsec - start.tv_nsec)) * 1e-9;
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
