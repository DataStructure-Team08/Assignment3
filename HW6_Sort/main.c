#define _CRT_SECURE_NO_WARNINGS
#include "sorting.h"
#include "common.h"
#include <time.h>

void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;  // 0부터 9999까지의 무작위 숫자
    }
}

int main() {
    int n = 10000;  // 배열 크기
    int numTests = 5;  // 각 크기에서 5번의 테스트
    clock_t start, end;
    double time_taken;
    double sum = 0;

    // 파일 열기
    FILE* file = fopen("Sort_Merge.txt", "w");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return 1;
    }

    // 배열 동적 할당
    int* arr = (int*)malloc(n * sizeof(int));

    // 무작위 데이터 생성을 위한 시드 설정
    srand(time(NULL));

    fprintf(file, "size,time\n");
    while (n <= 1000000) {
        //이 과정을 bubble, selection, insertion에 대해 각각 수행한다.
        sum = 0;
        arr = (int*)malloc(n * sizeof(int));
        fprintf(file, "%d,", n);
        // 배열 크기에 대해 5번 테스트
        for (int test = 1; test <= numTests; test++) {
            generateRandomArray(arr, n);  // 무작위 배열 생성

            // 버블 정렬 시작 시간 측정
            start = clock();

            //정렬 수행
            //quickSort(arr, 0, n - 1);
            mergeSort(arr, 0, n - 1);
            //heapSort(arr, n - 1);

            // 버블 정렬 종료 시간 측정
            end = clock();

            // 실행 시간 계산
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            sum += time_taken;
            // 결과 출력 및 파일에 기록
            printf("Test %d: 힙 정렬 실행 시간: %.6f 초\n", test, time_taken);
            //fprintf(file, "Test %d: %.6f \n", test, time_taken);  // 파일에 기록
        }
        printf("Average : %.6f 초\n", sum / numTests);
        fprintf(file, "%.6f\n", sum / numTests);
        n += 10000;
    }

    // 메모리 해제
    free(arr);

    // 파일 닫기
    fclose(file);

    printf("결과가 %s 파일에 저장되었습니다.\n", "test.txt");

    return 0;
}