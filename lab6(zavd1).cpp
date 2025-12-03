#include <iostream>
#include <ctime>

using namespace std;

template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

int main() {
    setlocale(LC_ALL, "ukr");
    const int n = 15;
    double y[n];



    cout << "Згенерований масив: ";
    for (int i = 0; i < n; i++) {
        y[i] = (rand() % 1000) / 10;
        cout << y[i] << " | ";
    }

    selectionSort(y, n);

    cout << "\nВідсортовані значення:\n";
    for (int i = 0; i < n; i++) {
        cout << y[i] << " | ";
    }

    cout << endl;
    return 0;
}
