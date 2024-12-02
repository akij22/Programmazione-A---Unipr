#include <iostream>
using namespace std;

int main() {

    int* A[1000];

    int choice, index = 0;
    bool status;
    bool found = false;
    int i = 0, countNewVariables = 0;

    do {

        // Resetto found per iterare su un nuovo elemento ancora non analizzato
        found = false;
        cout << "Inserire un numero: ";
        cin >> choice;
        cin.ignore();
        status = cin.fail();
        if (status) {
            cin.clear();
            cin.ignore(5000, '\n');

        } else if (choice != -1) {

            for (int j = 0; j < i; j++) {
                if (*A[j] == choice && found == false) {

                    found = true;
                    index = j;
                }
            }

            if (found) {

                // La variabile esiste, quindi il puntatore dell'array punta all'indirizzo della variabile gia esistente
                A[i] = A[index];
            } else {

                // La variabile non esiste, quindi la creo per la prima volta
                int* v = new int;
                *v = choice;

                // Debug: stampo cosa contiene v (indirizzo di memoria della variabile allocata nello heap)
                // e il suo relativo valore

                A[i] = v;

                countNewVariables++;
            }
            i++;
        }

    } while (choice != -1 || status);

    cout << "Allocate " << countNewVariables << " variabili" << endl;


    for (int j = 0; j < i; j++) {
        cout << *A[j] << " ";
    }

    cout << endl;

    // PARTE DI DEALLOCAZIONE
     bool deallocated = false;

    // Array per memorizzare gli indici dei puntatori già deallocati
    // (per evitare double-free)
    int indiciToDelete[100];

    // Indice di supporto
    int h = 0;

    for (int j = 0; j < i; j++) {
        deallocated = false;
        for (int k = 0; k <= j; k++) {

            // A[j] = puntatore attuale che sto confrontando
            // con tutti gli altri
            if (*A[j] == *A[k] && j != k && !deallocated) {

                // Se ho trovato un duplicato memorizzo la sua posizione in un array di supporto
                indiciToDelete[h] = j;
                deallocated = true;
                h++;
            }
        }
    }



    bool notDeallocate = false;

    for (int j = 0; j < i; j++) {
        notDeallocate = false;

        for (int k = 0; k < h; k++){
            if (j == indiciToDelete[k])
                notDeallocate = true;
        }
        if (!notDeallocate) {
            // cout << "Dealloco puntatore " << *A[j] << " in posizione " << j << endl;
            delete A[j];
        }

    }


    return 0;
}