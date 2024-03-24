#include <stdio.h>
int findLargest(int arr[], int size) {
    int largest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}
int findSmallest(int arr[], int size) {
    int smallest = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < smallest) {
            smallest = arr[i];
        }
    }
    return smallest;
}

int findSum(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return sum;
}

double findAverage(int arr[], int size) {
    int sum = findSum(arr, size);
    return (double)sum / size;
}

int main() {
    int size;

    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; ++i) {
        scanf("%d", &arr[i]);
    }

    int largest = findLargest(arr, size);
    int smallest = findSmallest(arr, size);
    int sum = findSum(arr, size);
    double average = findAverage(arr, size);

    printf("Largest element: %d\n", largest);
    printf("Smallest element: %d\n", smallest);
    printf("Sum of elements: %d\n", sum);
    printf("Average of elements: %.2lf\n", average);

    return 0;
}

