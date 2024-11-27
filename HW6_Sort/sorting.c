#include "sorting.h"
#include<stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    }
}
void merge(int list[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = 0;
    int size = right - left + 1;
    int* temp = (int*)malloc(size * sizeof(int)); // 최소한의 임시 배열

    if (temp == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    // 병합 과정
    while (i <= mid && j <= right) {
        if (list[i] <= list[j]) {
            temp[k++] = list[i++];
        }
        else {
            temp[k++] = list[j++];
        }
    }

    while (i <= mid && k < size) {
        temp[k++] = list[i++];
    }
    while (j <= right && k < size) {
        temp[k++] = list[j++];
    }

    // 임시 배열 내용을 원 배열에 복사
    for (k = 0; k < size; k++) {
        list[left + k] = temp[k];
    }

    free(temp); // 임시 배열 해제
}

void mergeSort(int list[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        merge(list, left, mid, right);
    }
}
void heapSort(int arr[], int length) {
    int i;

    buildMaxHeap(arr, length);			// 먼저 힙을 만든다.
    for (i = length - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);		// 부모노드와 마지막 노드와 SWAP
        length--;				// 부모노드를 삭제.
        maxHeapify(arr, 0, length);		// 힙 유지 실시.
    }
}
void buildMaxHeap(int arr[], int length) {

    int parent_position;

    // 리프 노드를 제외한 맨 마지막 노드부터 시작.
    // 배열은 0부터 시작하므로 length/2에 -1을 해줘야함.
    for (parent_position = length / 2 - 1; parent_position >= 0; parent_position--) {
        maxHeapify(arr, parent_position, length);	// 힙 유지 실시.
    }
}

void maxHeapify(int arr[], int parent_position, int heap_size) {
    int left, right, largest;

    left = 2 * parent_position + 1;
    right = 2 * parent_position + 2;

    if ((left < heap_size) && (arr[left] > arr[parent_position])) // 왼쪽 자식 노드와 부모노드 비교.
        largest = left;
    else
        largest = parent_position;

    if ((right < heap_size) && (arr[right] > arr[largest]))	// 오른쪽 자식노드와 이전에 얻은 제일 큰 노드 값과 비교.
        largest = right;

    if (largest != parent_position) {
        swap(&arr[parent_position], &arr[largest]);	// 값이 큰 노드를 부모노드로 SWAP.
        maxHeapify(arr, largest, heap_size);	// 다시 부모노드를 대상으로 Heapify를 실시.
    }
}
