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


int getZeroSubSequence(int a[], int n) {

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            int sum = 0;

            for (int k = i; k <= j; k++) {
                sum+= a[k];
            }

            if (sum == 0) {
                count ++;
                cout << "Trovata sottosequenza ad iterazione " << i << endl;
            }
        }
    }
    return count;
}

int nSottoSequenze(int a[], int n, int k) {
    int totalCount = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum = 0;

            for (int k2 = i; k2 <= j; k2++) {
                sum = sum + a[k2];
            }

            if (sum == k) {
                totalCount++;
                cout << "trovata sotto sequenza iterazione " << i << j << endl;
            }
        }
    }

    return totalCount;
}

void reverseArray(int a[], int n) {
    int j = n - 1;
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        j--;
    }

}

int main() {

    int a[5] = {1, 2, 7, 1, 7};
    int a2[5] = {5, 4, 3, 2, 1};
    int a3[6] = {2, 3, -2, 1, -2, 5};
    int a4[7] = {1, 2, -3, 7, -1, 4, 3};
    int a5[6] = {1, 2, 3, 4, 5, 6};


    int* b = new int[5];

    int result = compact(a, 5, b);

    cout << result << endl;

    printArray(b, result);

    bubbleSort(a2, 5);

    cout << endl << endl;
    printArray(a2, 5);


    cout << "Trovata " <<getZeroSubSequence(a3, 6) << " sottosequenza" << endl;

    delete [] b;

    cout << endl;
    cout << nSottoSequenze(a4, 7, 3) << endl;

    reverseArray(a5, 6);

    printArray(a5, 6);
    return 0;
}