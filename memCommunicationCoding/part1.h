#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

uint32_t* random_array(uint32_t buff_size, uint32_t sub_iters);
void run_tests(uint32_t buff_begin, uint32_t buff_end, uint32_t sub_iters);
