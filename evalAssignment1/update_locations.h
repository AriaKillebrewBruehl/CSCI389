#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

float * generate_random_list(int32_t size, int32_t bound);

void update_coords(float * xs, float * ys, float * zs, float * vx, float * vy, float * vz, int32_t size);

float sum(float * array, int32_t size);

