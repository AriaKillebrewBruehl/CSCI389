#include "part1.h"

uint32_t* random_array(uint32_t buff_size, uint32_t sub_iters) {

    uint32_t* randoms = (uint32_t*)malloc(sizeof(uint32_t) * sub_iters);

    for (int i =0; i < sub_iters; i++) {
        randoms[i] =  (uint32_t)(rand() % buff_size);
    }

    return randoms
}

double get_average_time(uint32_t buff_size3, uint32_t iters, uint32_t sub_iters) {

}

int main(void) {

}