#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include "functions.h"

int main() {
    int n = 0;
    int choiceArray = 0, choiceSorting = 0, validSize = 0, validArray = 0;
    srand((int) time(NULL));
    do {
        do {
            printf("Enter the size of your array(from 2 to 1000):");
            validSize = scanf("%d", &n);
            fflush(stdin);
            if (validSize != 1 || n < 2 || n > 1000) {
                printf("Invalid input. The size of array must be from 1 to 50\n");
                validSize = 0;
            }
        } while (!validSize);

        double arr[n] = {};

        printf("\nPlease select the method of setting the array (0 - generated, 1 - manually):");
        inputChoice(&choiceArray);

        switch (choiceArray) {
            case 0:
                printf("\nGenerated array:");
                generateRandomArray(arr, n);
                printArray(arr, n);
                break;
            case 1:
                printf("Enter elements of your array (%d):", n);
                for (int i = 0; i < n; i++) {
                    printf("\nElement (%d):", i + 1);
                    do {
                        validArray = scanf("%lf", &arr[i]);
                        fflush(stdin);
                        if (validArray != 1 || arr[i] < -10000 || arr[i] > 10000) {
                            printf("Invalid input.");
                            printf("\nElement (%d):", i + 1);
                            validArray = 0;
                        }
                    } while (!validArray);
                }
                break;
            default:
                break;
        }

        printf("\nPlease select the method of sorting the array (0 - descending, 1 - ascending):");
        inputChoice(&choiceSorting);

        switch (choiceSorting) {
            case 0:
                descendingBubbleSort(arr, n);
                break;
            case 1:
                ascendingBubbleSort(arr, n);
                break;
            default:
                break;
        }

        printf("\nSorted array:");
        printArray(arr, n);
        printf("\n");
        printf("Press ENTER to continue, or any other key to EXIT\n");
    } while (getch() == 13);
    return 0;
}