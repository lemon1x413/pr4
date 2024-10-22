#include <stdio.h>


void bubbleSort(double arr[], int n) {
    int i, j;
    double temp;

    // Основний цикл для бульбашкового сортування
    for (i = 0; i < n - 1; i++) {
        // Проходимо по масиву і порівнюємо сусідні елементи
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Міняємо місцями, якщо елемент більший за наступний
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;

    // Введення кількості елементів масиву
    printf("Enter the value of your array:");
    scanf("%d", &n);

    // Оголошення масиву
    double arr[n];

    // Введення елементів масиву
    printf("Enter elements of your array %d:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
    }

    // Виклик функції для сортування
    bubbleSort(arr, n);

    // Виведення відсортованого масиву
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", arr[i]);
    }
    printf("\n");

    return 0;
}
