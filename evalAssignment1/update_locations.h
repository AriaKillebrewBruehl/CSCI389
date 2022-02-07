#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int8_t * generate_random_list(int32_t size, int32_t bound);

void update_coords(int8_t * xs, int8_t * ys, int8_t * zs, int8_t * vx, int8_t * vy, int8_t * vz, int32_t size);

int8_t sum(int8_t * array, int32_t size);

