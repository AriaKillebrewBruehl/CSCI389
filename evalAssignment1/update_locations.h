#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int64_t * generate_random_list(int32_t size, int32_t bound);

void update_coords(int64_t * xs, int64_t * ys, int64_t * zs, int64_t * vx, int64_t * vy, int64_t * vz, int32_t size);

int64_t sum(int64_t * array, int32_t size);

