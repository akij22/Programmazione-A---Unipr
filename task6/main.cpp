#include <iostream>
using namespace std;

/*
 * Memorizzare: NOME, COGNOME, NUMERO DI TELEFONO
 * Contatti memorizzati in un array di MASSIMO 100 elementi --> array di struct
 * nTelefono è una stringa (C style)
 * Un contatto della rubrica = STRUCT
 * bool isDeleted --> per gestire i contatti eliminati (in fase di stampa)
 */


struct contatto {
    char nome[50];
    char cognome[50];
    char nTelefono[50];
    bool isDeleted;
};

int main() {

    // Definizione dei contatti in un array
    contatto contatti[100];
    int scelta = 0;
    int status;
    int nContatti = 0;
    int checkNContatti = 0;
    
    cout << "*** Rubrica ***" << endl;
    do {
        do {
            cout << "\t1 - Visualizza rubrica" << endl;
            cout << "\t2 - Inserisci contatto" << endl;
            cout << "\t3 - Cancella contatto" << endl;
            cout << "\t4 - Esci" << endl;
            cout << "-->";
            cin >> scelta;


            // Ignoro il carattere '\n', in modo da permettere i successivi inserimenti
            cin.ignore();
            status = cin.fail();
            if (status) {
                cin.clear();
                cin.ignore(5000, '\n');
            }

        } while (scelta > 4 || scelta < 1);

        if (scelta == 1) {
            // Stampa della rubrica


            for (int i = 0; i < nContatti; i++) {
                if (contatti[i].isDeleted == false) {
                    cout << "------------------------------" << endl;
                    // cout << "Contatto n. " << i + 1 << endl;
                    cout << "Nome della rubrica: " << contatti[i].nome << endl;
                    cout << "Cognome della rubrica: " << contatti[i].cognome << endl;
                    cout << "Numero di telefono della rubrica: " << contatti[i].nTelefono << endl;
                    cout << "------------------------------" << endl;
                    checkNContatti++;
                }
            }

            if (checkNContatti == 0) {
                cout << "Rubrica vuota!" << endl;
            }


        } else if (scelta == 2) {
            contatto c;
            bool checkInserimento;

            // Evito inserimento di contatti uguali, per evitare problemi durante l'eliminazione
            do {
                checkInserimento = false;

                // Inserimento nome
                cout << "Inserisci il nome del contatto da aggiungere: ";
                cin.getline(c.nome, 49, '\n');

                cout << "Inserisci il cognome del contatto da aggiungere: ";
                cin.getline(c.cognome, 49, '\n');

                for (int i = 0; i < nContatti; i++) {
                    if (strcmp(contatti[i].nome, c.nome) == 0 && strcmp(contatti[i].cognome, c.cognome) == 0 && contatti[i].isDeleted == false)
                        checkInserimento = true;
                }

                if (checkInserimento)
                    cout << "Contatto duplicato! Per favore, inserisci un nuovo contatto" << endl;
            } while (checkInserimento);

            cout << "Inserisci il numero del contatto da aggiungere: ";
            cin.getline(c.nTelefono, 49, '\n');

            // Controllo che il numero di telefono
            // sia composto da soli numeri

            contatti[nContatti] = c;
            contatti[nContatti].isDeleted = false;
            nContatti++;

        cout << "Contatto aggiunto!" << endl;
        }else if (scelta == 3){
            if (checkNContatti > 0) {
                // int indiceToDelete;
                char nomeToDelete[50];
                char cognomeToDelete[50];
                bool found = false;;


                // Controllo dell'inserimento del nome e cognome da cancellarw

                do {
                    cout << "Inserisci il nome del contatto da cancellare: ";
                    cin.getline(nomeToDelete, 49, '\n');

                    cout << "Inserisci il cognome del contatto da cancellare: ";
                    cin.getline(cognomeToDelete, 49, '\n');

                    for (int i = 0; i < nContatti; i++) {
                        if (strcmp(contatti[i].nome, nomeToDelete) == 0 && strcmp(contatti[i].cognome, cognomeToDelete) == 0 && contatti[i].isDeleted == false)
                            found = true;
                    }

                    if (!found)
                        cout << "Nessun contatto trovato con questo nome e cognome, riprova!" << endl;

                } while (!found);

                for (int i = 0; i < nContatti; i++) {
                    if (strcmp(nomeToDelete, contatti[i].nome) == 0 && strcmp(cognomeToDelete, contatti[i].cognome) == 0) {
                        contatti[i].isDeleted = true;
                    }
                }

                cout << "Contatto eliminato!" << endl;

                checkNContatti--;
            } else
                cout << "Rubrica vuota! Non puoi cancellare alcun contatto" << endl;

		}
    } while (scelta != 4);

    cout << "Addio!" << endl;
    

    return 0;
}
