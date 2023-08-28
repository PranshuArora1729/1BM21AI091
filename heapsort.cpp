#include <iostream>
#include <ctime>
#include <cstdlib>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    srand(time(nullptr)); // Seed the random number generator

    int n;
    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    int arr[n];
    int choice;

    std::cout << "Choose input method:\n";
    std::cout << "1. Manual entry\n";
    std::cout << "2. Random numbers\n";
    std::cin >> choice;

    if (choice == 1) {
        std::cout << "Enter the elements:\n";
        for (int i = 0; i < n; i++)
            std::cin >> arr[i];
    } else if (choice == 2) {
        for (int i = 0; i < n; i++)
            arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    } else {
        std::cout << "Invalid choice\n";
        return 1;
    }

    clock_t start_time = clock();
    heapSort(arr, n);
    clock_t end_time = clock();

    std::cout << "Sorted array:\n";
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " ";

    double time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
    std::cout << "\nTime taken: " << time_taken << " seconds\n";

    return 0;
}
