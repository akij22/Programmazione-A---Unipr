#include <iostream>
using namespace std;

// Funzione
// DA SPOSTARE NEL MAIN
void f (int* pointer[1000]) {
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
                if (*pointer[j] == choice && found == false) {
                    cout << "Variabile già presente!" << endl;
                    found = true;
                    index = j;
                }
            }

            if (found) {

                // La variabile esiste, quindi il puntatore dell'array punta all'indirizzo della variabile gia esistente
                pointer[i] = pointer[index];
            } else {

                // La variabile non esiste, quindi la creo per la prima volta

                // DA RIMUOVERE
                cout << "Variabile non presente, quindi la alloco dinamicamente..." << endl;
                int* v = new int;
                *v = choice;

                // Debug: stampo cosa contiene v (indirizzo di memoria della variabile allocata nello heap)
                // e il suo relativo valore

                // DA RIMUOVERE
                cout << v << " " << *v << endl;
                pointer[i] = v;

                countNewVariables++;
            }
            i++;
        }

    } while (choice != -1 || status);

    cout << "Allocate " << countNewVariables << " variabili" << endl;
    for (int j = 0; j < i; j++) {

        // DA RIMUOVERE
        cout << "Indirizzo di memoria della variabile nello heap: " << pointer[j] << ", valore: " << *pointer[j] << endl;
    }



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

            // pointer[j] = puntatore attuale che sto confrontando
            // con tutti gli altri
            if (*pointer[j] == *pointer[k] && j != k && !deallocated) {

                // Se ho trovato un duplicato memorizzo la sua posizione in un array di supporto
                indiciToDelete[h] = j;
                deallocated = true;
                h++;
            }



        }
    }



    bool notDeallocate = false;
    // int y = 0;
    // Parte di deallocazione
    for (int j = 0; j < i; j++) {
        notDeallocate = false;
        // cout <<  indiciToDelete[j] << " " << endl;

        for (int k = 0; k < h; k++){
            if (j == indiciToDelete[k])
                notDeallocate = true;
        }
        if (!notDeallocate) {
            cout << "Dealloco puntatore " << *pointer[j] << " in posizione " << j << endl;
            delete pointer[j];
        }

    }


}


int main() {

    int* pointer[1000];



    f(pointer);



    return 0;
}