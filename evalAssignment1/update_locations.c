#include "update_locations.h"

// Create a list of 'size' doubleing point numbers in the range [-bound, bound]
double * generate_random_list(int32_t size, int32_t bound) {
    double* array;
    array = (double*)malloc(sizeof(double) * size);


    for (int i = 0; i < size; i++) {
        double num = (double)(rand() % (2*bound+1)) - bound;
        array[i] = num;
    }
    return array;
}

// Update position by velocity, one time-step
void update_coords(double * xs, double * ys, double * zs, double * vx, double * vy, double * vz, int32_t size){
    for (int i = 0; i < size; i ++) {
        xs[i] = xs[i] + vx[i];
        ys[i] = ys[i] + vy[i];
        zs[i] = zs[i] + vz[i];
    }
}

double sum(double * array, int32_t size) {
    double sum = 0;
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
    double * xs = generate_random_list(size, 1000);
    double * ys = generate_random_list(size, 1000);
    double * zs = generate_random_list(size, 1000);
    double * vx = generate_random_list(size, 1);
    double * vy = generate_random_list(size, 1);
    double * vz = generate_random_list(size, 1);

    struct timespec start, stop;
    clock_gettime(CLOCK_MONOTONIC, &start);
    for (int i=0; i < iters; i++) {
        update_coords(xs, ys, zs, vx, vy, vz, size);
    }
    clock_gettime(CLOCK_MONOTONIC, &stop);
    double chksum = sum(xs, size) + sum(ys, size) + sum(zs, size);
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
