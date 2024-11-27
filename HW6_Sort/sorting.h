#ifndef SORT
#define SORT
#include<stdio.h>
#include <stdlib.h>
int* sorted;

void swap(int* a, int* b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void merge(int list[], int left, int mid, int right);
void mergeSort(int list[], int left, int right);
void heapSort(int arr[], int length);
void buildMaxHeap(int arr[], int length);
void maxHeapify(int arr[], int parent_position, int heap_size);

#endif