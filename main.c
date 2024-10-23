#include <stdio.h>
#include <conio.h>
void bubbleSort(double arr[], int n) {
    double temp;

    // Основний цикл для бульбашкового сортування
    for (int i = 0; i < n - 1; i++) {
        // Проходимо по масиву і порівнюємо сусідні елементи
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                // Міняємо місцями, якщо елемент більший за наступний
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    unsigned n;
    char validSize = 0, validArray = 0;
    do {
        do {
            // Введення кількості елементів масиву
            printf("Enter the size of your array(from 1 to 50):");
            validSize = scanf("%u", &n);
            fflush(stdin);
            if (validSize !=1 || n == 0 || n > 50) {
                printf("Invalid input. The size of array must be from 1 to 50\n");
                validSize = 0;
            }
        } while (!validSize);

        double arr[n];

        // Введення елементів масиву
        printf("Enter elements of your array (%d):\n", n);
        for (int i = 0; i < n; i++) {
            do {
                validArray = scanf("%lf", &arr[i]);
                fflush(stdin);
                if (validArray !=1) {
                    printf("Invalid input.\n");
                    validArray = 0;
                }
            } while (!validArray);
        }

        // Виклик функції для сортування
        bubbleSort(arr, n);

        // Виведення відсортованого масиву
        printf("Sorted array:\n");
        for (int i = 0; i < n; i++) {
            printf("%.2lf ", arr[i]);
        }
        printf("\n");

        printf ("Press ENTER to continue, or any other key to EXIT");
    } while (getch()==13);
    return 0;
}