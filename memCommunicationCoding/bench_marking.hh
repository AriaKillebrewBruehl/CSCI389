#pragma once

#include <iostream>
#include <time.h>
#include <math.h>
#include <string>


// typedef std::chrono::time_point<std::chrono::steady_clock> time_point_t;
// typedef long double ns_t;
uint32_t* random_list(uint32_t buff_size, int32_t sub_iters);
double run_measurement(int buff_size, int num_iters);
