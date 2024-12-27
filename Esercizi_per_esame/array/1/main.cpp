#include <iostream>
using namespace std;

bool isPresent(int b[], int dato, int n) {
    bool check = false;

    for (int i = 0; i < n; i++) {
        if (b[i] == dato)
            check = true;
    }

    return check;
}

int compact (int a[], int n, int b[]) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!isPresent(b, a[i], n)) {
            b[j] = a[i];
            count++;
            j++;
        }
    }
    return count;
}

void printArray (int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}


void bubbleSort (int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int main() {

    int a[5] = {1, 2, 7, 1, 7};
    int a2[5] = {5, 4, 3, 2, 1};
    int* b = new int[5];

    int result = compact(a, 5, b);

    cout << result << endl;

    printArray(b, result);

    bubbleSort(a2, 5);

    cout << endl << endl;
    printArray(a2, 5);

    delete [] b;
    return 0;
}