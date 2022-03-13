#include "bench_marking.hh"

double run_measurement(int buff_size, int num_iters, int sub_iters) {
    struct timespec start, stop;                                    // initialize clock

    char* array = (char*)malloc(sizeof(char) * buff_size);          // create char array of size biff_size

    double* times = (double*)malloc(sizeof(double) * num_iters);    // create array to hold sizes

    double total_time = 0;

    for (int i = 0; i < num_iters; i++) {
        int num = (int)(rand() % buff_size);                        // random index in array to avoid prefetching

        clock_gettime(CLOCK_MONOTONIC, &start);                     // start clock
        for (int j = 0; j < sub_iters; j++) {                       // fetch random array element sub_iters times
            char c = array[num];
        }
        clock_gettime(CLOCK_MONOTONIC, &stop);

        double object_count = sub_iters;                            // set object count to number of times time was measured in subloop
        double time_taken;                                          // calculate time taken in nanoseconds
        // time_taken = (stop.tv_sec - start.tv_sec) * 1e9;
        // time_taken = (time_taken + (stop.tv_nsec - start.tv_nsec)) * 1e-9;
        // time_taken = time_taken * 1e6 / object_count;
        time_taken = stop.tv_nsec - start.tv_nsec;
        time_taken /= object_count;

        times[i] = time_taken;
        total_time += time_taken;
    }

    double avg_time = total_time / buff_size;                       // find average time

    return avg_time;

}

int main(void) {
    std::string header = "buffer size | mean time (ns)";
    std::cout << header << std::endl;

    for (int i = 2; i <= std::pow(2, 10) ; i*= 2) {                  // for various buffer sizes
        std::cout << std::string(header.length(), '-') << std::endl;

        int spaces = std::log10(i);
        double time = run_measurement(i, std::pow(i, 2), 100);       // calculate latency

        std::string time_string = std::to_string(time);
        int time_spaces = time_string.length();

        std::cout << i << std::string((10 - spaces), ' ') << " | "
            << std::string((14 - time_spaces), ' ') << time_string << std::endl;
    }


    return 0;
}