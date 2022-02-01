/*
Write C code that generates a list of random integers and computes the mean (as a real number).
Your program should take as input two parameters, the length of the list, and a seed to generate
the random numbers. It should print out the list of integers and the calculated mean.
Submit your code, as well as the makefile you used to compile it. */

#include <stdio.h>
#include <stdlib.h>

int * randomArray(int size, double seed) {
    static int* array;
    array = (int*)malloc(size *sizeof(int));
    srand(seed);

    for (int i = 0; i < size; i++) {
        int num = rand();
        array[i] = num;
    }

    return array;
}

int sumArray(int *array) {
    int sum = 0;
    for (int i = 0; i < sizeof(array); i++) {
        sum += array[i];
    }
    return sum;
}

void print_array(int *array) {
    printf("[");
    for (int i =0; i < sizeof(array) - 1; i++ ) {
        printf("%d,", array[i]);
    }
    printf("%d", array[sizeof(array) - 1]);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Must pass exactly two arguments (length of integer list and random seed).");
        return -1;
    } else if (*argv[2] < 1) {
        fprintf(stderr, "Length of integer list must be greater than or equal to one.");
        return -1;
    }

    int length = *argv[1];
    int seed = *argv[2];

    int * array = randomArray(length, seed);
    int sum = sumArray(array);

    double mean = sum / length;

    printf("The integer list is: ");
    print_array(array);
    printf("\n");
    printf("The mean of the array is: %f.", mean);

    return 0;
}