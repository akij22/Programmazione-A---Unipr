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

bool isMultiple(int a[], int dato, int n) {
    bool final = false;
    int check = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] == dato && check > 0)
            final = true;
        else if (a[i] == dato && check == 0)
            check++;
    }
    return final;
}


int compact_V2(int a[], int n, int b[]) {
    int count = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        if (!isMultiple(a, a[i], n)) {
            b[j] = a[i];
            j++;
            count++;
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

    int indice = n - 1;

    for (int i = 0; i <= n / 2; i++) {
        int temp = a[i];
        a[i] = a[indice];
        a[indice] = temp;
        indice--;
    }
}

void ruota_avanti(int a[], int n) {
    int element = a[n - 1];

    for (int i = n -1; i > 0; i--)
        a[i] = a[i - 1];

    a[0] = element;
}

void ruota_indietro(int a[], int n) {
    int element = a[0];

    for (int i = 0; i < n - 1; i++) {
        a[i] = a[i + 1];
    }

    a[n - 1] = element;
}

int main() {

    int a[5] = {1, 2, 7, 1, 7};
    int a2[5] = {5, 4, 3, 2, 1};
    int a3[6] = {2, 3, -2, 1, -2, 5};
    int a4[7] = {1, 2, -3, 7, -1, 4, 3};
    int a5[6] = {1, 2, 3, 4, 5, 6};


    int* b = new int[5];
    int* b2 = new int[5];

    int result = compact(a, 5, b);

    int result2 = compact_V2(a, 5, b2);

    cout << result << endl;

    cout << "Risultato versione differente: " << result2 << endl;

    printArray(b, result);

    bubbleSort(a2, 5);

    cout << endl << endl;
    printArray(a2, 5);


    cout << "Trovata " <<getZeroSubSequence(a3, 6) << " sottosequenza" << endl;

    delete [] b;
    delete [] b2;

    cout << endl;
    cout << nSottoSequenze(a4, 7, 3) << endl;

    cout << "Array prima: ";
    printArray(a5, 6);

    reverseArray(a5, 6);

    cout << "Array dopo: ";

    printArray(a5, 6);

    cout << endl;
    ruota_avanti(a, 5);
    printArray(a, 5);

    cout << endl;
    ruota_indietro(a, 5);
    printArray(a, 5);
    return 0;
}