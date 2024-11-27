#ifndef COMMON
#define COMMON

#include<stdlib.h>
#include<stdio.h>
#include<time.h>

int* array(int n);
void print_array(int*, int);
void freeArray(int* arr);
int mrand(int range);

#endif