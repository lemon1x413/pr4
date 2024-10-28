
#ifndef OP4_FUNCTIONS_H
#define OP4_FUNCTIONS_H

#include <math.h>

double random(double min, double max) {
    double range = (max - min);
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

void generateRandomArray(double *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = random(-10000.0, 10000.0);
    }
}

void descendingBubbleSort(double arr[], int n) {
    double temp;
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

void ascendingBubbleSort(double arr[], int n) {
    double temp;
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
    int valid = 0;
    do {
        valid = scanf("%d", &*choice);
        fflush(stdin);
        if (valid != 1 || *choice != 0 && *choice != 1) {
            printf("\nPlease, try again!");
            valid = 0;
        }
    } while (!valid);
}

void printArray(double *arr, int n) {
    int maxNumberLength = n == 0 ? 1 : (int) log10(n) + 2;
    for (int i = 0; i < n; i++) {
        if (i % 10 == 0) {
            printf("\n");
        }
        printf("|| %*s%-12.2lf", maxNumberLength, " ", arr[i]);
    }
}

#endif //OP4_FUNCTIONS_H