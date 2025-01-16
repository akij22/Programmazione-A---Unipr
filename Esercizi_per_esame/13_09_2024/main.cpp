#include <iostream>
using namespace std;

void swap(int a[], int b[], int n) {
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main() {


    int a[5] = {1, 6, 2, 2, 4};
    int b[5] = {3, 4, 5, 4, 1};

    swap(a, b, 5);

    printArray(a, 5);
    printArray(b, 5);

    return 0;
}