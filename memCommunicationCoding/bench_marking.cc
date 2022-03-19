#include "bench_marking.hh"

struct timespec diff(struct timespec start, struct timespec end) {
    struct timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        temp.tv_nsec = end.tv_nsec-start.tv_nsec;
    }
    return temp;
 }

uint32_t* random_list(uint32_t buff_size, int32_t sub_iters) {
    uint32_t* randoms = (uint32_t*)malloc(sizeof(uint32_t) * sub_iters);

    for (int i = 0; i < sub_iters; i++) {
        uint32_t num = (uint32_t)(rand() % buff_size);
        randoms[i] = num;
    }

    return randoms;
}
double run_measurement(uint32_t buff_size, int32_t num_iters, int32_t sub_iters) {
    struct timespec start, stop;                                    // initialize clock

    char* array = (char*)malloc(sizeof(char) * buff_size);          // create char array of size biff_size
    uint32_t* random_indices = random_list(buff_size, sub_iters);

    double total_time = 0;
    char c;

    for (int i = 0; i < num_iters; i++) {

        clock_gettime(CLOCK_MONOTONIC, &start);                     // start clock
        for (int j = 0; j < sub_iters; j++) {                       // fetch random array element sub_iters times
            c = array[random_indices[j]];
        }
        clock_gettime(CLOCK_MONOTONIC, &stop);

        struct timespec dif = diff(start, stop);

        double time_taken = dif.tv_nsec / sub_iters;

        total_time += time_taken;
    }

    double avg_time = total_time / num_iters;                       // find average time

    free(array);
    free(random_indices);

    return avg_time;

}

int main(int argc, char* argv[]) {

    // if (argc != 2) {
    //     std::cerr << "Required arguments: max range of buffer sizes (N)" << std::endl;
    //     return -1;
    // }

    // int32_t buff_size = atoi(argv[1]);
    // if (buff_size & (buff_size - 1)) {
    //     std::cerr << "Max range of buffer sizes (N) must be a power of 2" << std::endl;
    //     return -1;
    // }

    std::string header = "buffer size | mean time (ns)";
    std::cout << header << std::endl;

    for (int i = 1024; i <= 4194305 ; i *= 2) {                  // for various buffer sizes
        std::cout << std::string(header.length(), '-') << std::endl;

        int spaces = std::log10(i);
        double time = run_measurement(i, i * 50, 50);       // calculate latency

        std::string time_string = std::to_string(time);
        int time_spaces = time_string.length();

        std::cout << i << std::string((10 - spaces), ' ') << " | "
            << std::string((14 - time_spaces), ' ') << time_string << std::endl;
    }


    return 0;
}