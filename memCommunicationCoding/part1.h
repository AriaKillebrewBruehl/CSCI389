#pragma once

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

uint32_t* random_array(uint32_t buff_size, uint32_t sub_iters);

// double get_average_time(uint32_t buff_size, uint32_t iters, uint32_t sub_iters);

struct timespec diff(struct timespec start, struct timespec end) {
    struct timespec temp;
    if ((end.tv_nsec-start.tv_nsec)<0) {
        temp.tv_sec = end.tv_sec-start.tv_sec-1;
        //temp.tv_nsec = 1000000000+end.tv_nsec-start.tv_nsec;
        temp.tv_nsec = (end.tv_sec * 1e9 + end.tv_nsec) - (start.tv_sec * 1e9 + start.tv_nsec);
    } else {
        temp.tv_sec = end.tv_sec-start.tv_sec;
        //temp.tv_nsec = end.tv_nsec-start.tv_nsec;
        temp.tv_nsec = (end.tv_sec * 1e9 + end.tv_nsec) - (start.tv_sec * 1e9 + start.tv_nsec);
    }
    return temp;
 }

