#include <iostream>
#include <cstring>
using namespace std;

int main() {


    // Stringa lunga max 100 + carattere terminatore (\0)
    char parola1[101];
    char parola2[101];
    int countCheck = 0;

    bool checked = false;
    bool found = false;


    do {

        // Resetto le variabili per ogni coppia di parole analizzata
        countCheck = 0;
        found = false;

        cout << "Inserire la prima parola: ";
        cin.getline(parola1, 100, '\n');

        if (parola1[0] != '$') {
            cout << "Inserire la seconda parola: ";

            cin.getline(parola2, 100, '\n');

            for (int i = 0; i < strlen(parola1); i++) {

                for(int j = 0; j < strlen(parola2); j++) {

                    if (parola1[i] == parola2[j] && checked == false) {
                        countCheck++;
                        checked = true;
                        found = true;
                    }
                }

                // Evito di contare i doppioni
                checked = false;
            }

            // NB: due parole uguali NON sono anagrammi
            if (countCheck == strlen(parola1) && strcmp(parola1, parola2) != 0) {
                cout << "Le due parole sono anagrammi" << endl;
            } else if (!found)
                cout << "Le due parole non hanno lettere in comune" << endl;

            cout << endl;
        }



    } while (parola1[0] != '$');

    cout << "Addio!";

    return 0;
}
