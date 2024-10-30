#ifndef OP4_FUNCTIONS_H
#define OP4_FUNCTIONS_H

#include <math.h>

float random(float min, float max) {
    float range = (max - min);
    float div = RAND_MAX / range;
    return min + ((float)rand() / div);
}

void generateRandomArray(float *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = random(-10000, 10000);
    }
}

void descendingBubbleSort(float *arr, int n) {
    float temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void ascendingBubbleSort(float *arr, int n) {
    float temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void inputChoice(const int *choice) {
    char valid = 0;
    do {
        valid = scanf("%d", &*choice);
        if (valid != 1 || *choice != 0 && *choice != 1) {
            printf("\nPlease, try again!");
            valid = 0;
        }
        fflush(stdin);
    } while (!valid);
}

void printArray(float *arr, int n) {
    int maxNumberLength = n == 0
                             ? 1
                             : (int) log10(n) + 2;
    for (int i = 0; i < n; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("|%*s%-12.2lf", maxNumberLength, " ", arr[i]);
    }
}

#endif //OP4_FUNCTIONS_H