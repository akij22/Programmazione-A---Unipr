#include <iostream>
using namespace std;

// Funzione
void f (int* pointer[100]) {
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
                int* v = new int;
                *v = choice;

                // Debug: stampo cosa contiene v (indirizzo di memoria della variabile allocata nello heap)
                // e il suo relativo valore
                cout << v << " " << *v << endl;
                pointer[i] = v;

                countNewVariables++;
            }
            i++;
        }

    } while (choice != -1 || status);

    cout << "Allocate " << countNewVariables << " variabili" << endl;
    for (int j = 0; j < i; j++) {
        cout << "Indirizzo di memoria della variabile nello heap: " << pointer[j] << ", valore: " << *pointer[j] << endl;
    }

}



int main() {

    int* pointer[1000];



    f(pointer);


    return 0;
}