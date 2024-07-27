#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

void displayArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < a[i]; j++) {
            cout << "** ";
        }
        cout << "(" << a[i] << ")";
        cout << "\n\n";
    }
    cout << "----------------------------------------------\n";
}

void delay(float t) {
    double i, j;
    t = t * 10000;
    for (i = 1; i <= (2 * t); i++)
        for (j = 0; j <= 10000; j++);
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
            }
        }
        displayArray(a, n);
        delay(0.5);
        system("cls");
    }
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[minIdx]) {
                minIdx = j;
            }
        }
        swap(a[i], a[minIdx]);
        displayArray(a, n);
        delay(0.5);
        system("cls");
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        displayArray(a, n);
        delay(0.5);
        system("cls");
    }
}

int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high, int n) {
    if (low < high) {
        int pi = partition(a, low, high);
        quickSort(a, low, pi - 1, n);
        quickSort(a, pi + 1, high, n);
        displayArray(a, n);
        delay(0.5);
        system("cls");
    }
}

void heapify(int a[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && a[left] > a[largest])
        largest = left;
    if (right < n && a[right] > a[largest])
        largest = right;
    if (largest != i) {
        swap(a[i], a[largest]);
        heapify(a, n, largest);
    }
}

void heapSort(int a[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(a, n, i);
    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        heapify(a, i, 0);
        displayArray(a, n);
        delay(0.5);
        system("cls");
    }
}

void generateArray(int a[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        a[i] = (rand() % 10) + 1; // Generate random number between 1 and 10
    }
}

int main() {
    int n, choice;
    char ch;
    do {
        cout << "Enter the size of the array: ";
        cin >> n;
        int a[n];
        generateArray(a, n);
        cout << "Generated array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n----------------------------------------------\n";

        cout << "Select the sorting algorithm:\n";
        cout << "1. Bubble Sort\n";
        cout << "2. Selection Sort\n";
        cout << "3. Insertion Sort\n";
        cout << "4. Quick Sort\n";
        cout << "5. Heap Sort\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                bubbleSort(a, n);
                break;
            case 2:
                selectionSort(a, n);
                break;
            case 3:
                insertionSort(a, n);
                break;
            case 4:
                quickSort(a, 0, n - 1, n);
                displayArray(a, n);
                delay(0.5);
                system("cls");
                break;
            case 5:
                heapSort(a, n);
                break;
            default:
                cout << "Invalid choice!\n";
                break;
        }

        cout << "Sorted array: ";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\nSORTED!\n";

        delay(2);
        system("cls");

        cout << "\nPlay again? (y/n): ";
        cin >> ch;
    } while (ch == 'y');

    return 0;
}
