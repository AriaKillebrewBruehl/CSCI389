#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int16_t * generate_random_list(int32_t size, int32_t bound);

void update_coords(int16_t * xs, int16_t * ys, int16_t * zs, int16_t * vx, int16_t * vy, int16_t * vz, int32_t size);

int16_t sum(int16_t * array, int32_t size);

