#include <iostream>
using namespace std;

int main() {

    int n = 0;

    // i per le righe, j per le colonne
    int i, j;

    do {
        cout << "Inserisci un numero dispari positivo: ";
        cin >> n;
    } while (n < 0 || n % 2 == 0);

    int check = n - 1;

    // Ciclo per le righe
    for (i= 0; i < n; i++) {

        // Ciclo per le colonne
        // (j <= n)
        for (j = 0; j < n; j++) {
            if (j == i || j == check)
                cout << "*";
            else
                cout << " ";
        }

        // Vado a capo e decremento check
        check --;
        cout << endl;

    }
    return 0;
}
