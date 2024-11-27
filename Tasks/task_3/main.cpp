#include <iostream>
using namespace std;

// Tavola pitagorica
// 1 2 3 4 5
// 2 4 6 8 10
// 3 6 9 12 15

int main() {


    int scelta, sommatore = 0;

    // Controllo dell'input
    do {
        cout << "Inserisci un valore intero (> 0): ";
        cin >> scelta;
        if (scelta <= 0)
            cout << "Input errato" << endl;
    } while (scelta <= 0);

    for (int i = 1; i <= scelta; i++) {

        // Azzero ad ogni nuova riga il sommatore
        sommatore = 0;

        for (int j = 1; j <= scelta; j++) {

            // Sommo il sommatore al valore della riga corrispondente
            sommatore += i;
            cout << sommatore << " ";
        }


        cout << endl;
    }


    return 0;
}
