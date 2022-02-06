#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

float * generate_random_list(int size, int bound);

void update_coords(float * xs, float * ys, float * zs, float * vx, float * vy, float * vz);

float sum(float * array);

