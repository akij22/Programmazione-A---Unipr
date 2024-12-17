#include <iostream>
#include <cstring>
using  namespace std;


// Trova le sottostringhe di due parole
bool findSubString (char* s1, char* s2) {

    bool find = false;

    for (int i = 0; s1[i] != '\0'; i++) {
        for (int j = 1; s1[i - 1 + j] |= '\0'; j++) {

            char sottostringa[100];
            strcpy(sottostringa, s1 + i);
            sottostringa[j] = '\0';

            if (strstr(s2, sottostringa) != nullptr) {
                find = true;
                cout << "Sottostringa: " << sottostringa << endl;
            }

        }
    }
    return find;
}


/*
 * Scrivere un programma in C++ che legge una stringa str e un carattere c
 * e stampa a video una nuova stringa che corrisponde a str con tutte le occorrenze del carattere c rimosse.
 */

void deleteByChar (char* string, char c) {

    bool found = false;

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == c) {
            for (int j = i; string[j] != '\0'; j++) {
                string[j] = string[j + 1];
            }
            found = true;

            // Resetto l'indice per rianalizzare la stringa
            i = 0;
        }
    }

    if (found)
        cout << string;
    else
        cout << "Carattere non presente nella stringa..." << endl;
}

int getLen(char* str) {
    if (str[0] == '\0')
        return 0;

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}

char* replace_spaces(char* str) {

    char* newS = new char[getLen(str)];

    if (str[0] == '\0') {
        cout << "Stringa vuota" << endl;
        return newS;
    }


    strcpy(newS, str);

    newS[getLen(str)] = '\0';

    for (int i = 0; newS[i] != '\0'; i++) {

        if (newS[i] == ' ') {
            newS[i] = '_';
        }
    }

    return newS;
}






int main() {

    // Lunghezza max della stringa = 100
    char str1[101], str2[101], str3[51];


    cout << "Inserire la prima parola: ";
    cin.getline(str1, 100);

    cout << "Inserire la seconda parola: ";
    cin.getline(str2, 100);

    if (findSubString(str1, str2))
        cout << "Esistono sottostringhe" << endl;
    else
        cout << "Non esistono sottostringhe" << endl;


    do {
        cout << "Inserire stringa: ";
        cin.getline(str3, 50, '\n');
    } while (cin.fail());

    char toDelete;
    cout << "Inserire carattere: ";
    cin >> toDelete;

    deleteByChar(str3, toDelete);


    char string[49] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '!', '\0'};

    char* newS = replace_spaces(string);

    cout << newS << endl;

    delete newS;




    return 0;
}