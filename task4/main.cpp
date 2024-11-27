#include <iostream>
#include <cmath>
using namespace std;

int main() {

    int n = 0, scelta;

    // Inserimento dimensione dell'array (= lunghezza del numero binario)
    do {
        cout << "Inserire numero di bits (>=2): ";
        cin >> n;
        if (n < 2)
            cout << "Errore!" << endl;
    } while (n < 2);

    int bits[n];

    // Inserimento del numero binario nell'array
    for (int i = n - 1; i >= 0; i--) {
        do {
            cout << "Inserisci il bit nella posizione " << i << ": ";
            cin >> bits[i];
            if (bits[i] != 1 && bits[i] != 0)
                cout << "Errore!" << endl;

        } while (bits[i] != 1 && bits[i] != 0);
    }


    // Menu di scelta
    do {
        cout << "Operazione: " << endl;
        cout << "\t0 - Stampa binario:" << endl;
        cout << "\t1 - Converti in decimale:" << endl;
        cout << "\t2 - Somma:" << endl;
        cout << "--> ";
        cin >> scelta;

        if (scelta > 2 || scelta < 0)
            cout << "Errore!" << endl;
    } while (scelta < 0 || scelta > 2);


    // Stampa del numero binario
    if (scelta == 0) {
        cout << "Numero binario: ";
        for (int i = n - 1 ; i >= 0; i--) {
            cout << bits[i];
        }

    } else if (scelta == 1) {
        double cNumber = 0;

        // Controllo il segno
        if (bits[n - 1] == 0) {
            for (int i = 0; i < n; i++) {
                cNumber = cNumber + pow(2, i) * bits[i];
            }

            cout << "Numero decimale: " << cNumber << endl;
        } else {
            int reversedBits[n];

            // Inverto i bit del numero originale
            for (int i = n - 1; i >= 0; i--) {

                if (bits[i] == 1)
                    reversedBits[i] = 0;
                else if (bits[i] == 0)
                    reversedBits[i] = 1;

                cNumber = cNumber + pow(2, i) * reversedBits[i];
            }
            cNumber+= 1;
            cNumber *= -1;
            cout << "Numero decimale: "<< cNumber << endl;
        }

    // Numero originale + 1
    } else if (scelta == 2) {

        bool riporto = true;
        int segno = bits[n-1];

        for (int i = 0; i < n; i++) {
            if(bits[i] == 1 && riporto == true) {
                bits[i] = 0;
            } else if (bits[i] == 0 && riporto == true) {
                bits[i] = 1;
                riporto = false;
            }

        }

        if(bits[n-1] != segno) {
            cout << "Overflow!" << endl;
        } else {

            cout << "Somma: ";
            for (int i = n - 1 ; i >= 0; i--) {
                cout << bits[i];
            }
        }

    }

    return 0;
}
