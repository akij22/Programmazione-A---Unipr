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


int main() {

    int a[5] = {1, 2, 7, 1, 7};
    int* b = new int[5];

    int result = compact(a, 5, b);

    cout << result << endl;

    delete [] b;
    return 0;
}