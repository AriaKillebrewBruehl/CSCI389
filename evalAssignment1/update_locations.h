#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double * generate_random_list(int32_t size, int32_t bound);

void update_coords(double * xs, double * ys, double * zs, double * vx, double * vy, double * vz, int32_t size);

double sum(double * array, int32_t size);

