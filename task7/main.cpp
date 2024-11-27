#include <iostream>
using namespace std;


int main() {

    int* pointer[1000];
    bool status;
    int choice, index = 0;
    int i = 0;
    int countNewVariables = 0;
    bool found = false;

    do {
        cout << "Inserire un numero: ";
        cin >> choice;

        cin.ignore();
        status = cin.fail();
        if (status) {
            cin.clear();
            cin.ignore(5000, '\n');

        } else if (choice != -1) {

            for (int j = 0; j < i; j++) {
                if (*pointer[j] == choice) {
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
                pointer[i] = v;
                countNewVariables++;
            }
            i++;
        }

    } while (choice != -1 || status);

    cout << "Allocate " << countNewVariables << " variabili" << endl;
    for (int j = 0; j < i; j++) {
        cout << "Indirizzo di memoria: " << pointer[j] << ", valore: " << *pointer[j] << endl;
    }

    return 0;
}