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

char* reverseNew(char* str) {
    char* newS = new char[getLen(str) + 1];

    int j = getLen(str) - 1;

    for (int i = 0; i < getLen(str); i++) {
        newS[i] = str[j];
        j--;
    }
    return newS;
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


int countTotal(char c, char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c)
            count++;
    }
    return count;
}

int countUnique(char* str) {
    if (str[0] == '\0')
        return 0;

    int counter = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (countTotal(str[i], str) == 1)
            counter++;
    }
    return counter;
}


int countParole (char* str) {
    if (str[0] == '\0')
        return 0;

    int countParole = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        while (str[i] != ' ' && str[i] != '\0')
            i++;
        countParole++;
    }
    return countParole;
}


void printSubString(char* str, int len) {
    for (int i = 0; i < len; i++) {
        for (int j = i; j < len; j++) {

            for (int k = i; k <= j; k++) {
                cout << str[k];
            }
            cout << endl;
        }
    }

}

bool findSottostringa(char* str, char* substr) {

    bool final = false;

    char* subStr = new char[getLen(str) + 1];

    if (str[0] == '\0')
        return false;

    int count = 0;
    for (int i = 0; i < getLen(str); i++) {
        for (int j = i; j < getLen(str); j++) {
            count = 0;

            for (int k = i; k <= j; k++) {
                subStr[count] = str[k];
                count++;
            }

            subStr[count] = '\0';
            if (strcmp(subStr, substr) == 0)
                final = true;
        }
    }

    delete [] subStr;
    return final;
}

int find_longest_word_lenght(char* s) {
    if (s[0] == '\0')
        return 0;

    int max = 0;
    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        count = 0;
        while (s[i] != ' ' && s[i] != '\0') {
            count++;
            i++;
        }

        if (count >= max)
            max = count;

    }
    return max;
}

int countWords(char* str) {
    if (str[0] == '\0')
        return 0;

    int count = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ')
            count++;
    }
    count++;
    return count;

}

int main() {

    // Lunghezza max della stringa = 100
    char str1[101], str2[101], str3[51];

    char str4[5] = {'c', 'i', 'a', 'o', '\0'};

    char* newS2 = reverseNew(str4);

    // char c = newS2[4];

    cout << endl << endl << newS2 << endl << endl;
    delete[] newS2;

    char str[101] = {'h', 'e', 'l', 'l', 'o', '\0'};
    char strr[101] = {'h', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', 'd', 'd', '\0'};

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

    cout << endl << newS << endl;

    delete newS;


    cout << endl;

    cout << "Numero di caratteri unici: " << countUnique(str) << endl;

    cout << countParole(strr) << endl;

    // ------------------------------------------------

    char string2[100] = {'c', 'i', 'a', 'o', '\0'};
    char sub[100] = {'i', 'a', 'o', '\0'};

    // char string3[4] = {'a', 'b', 'c', '\0'};


    printSubString(string2, 4);
    cout << endl;

    cout << findSottostringa(string2, sub) << endl;

    cout << find_longest_word_lenght(strr) << endl;

    char str8[101];

    // Pulisco lo stream per liberare da vecchi input
    cin.clear();

    fflush(stdin);

    cout << "Inserisci stringa: ";
    cin.getline(str8, 100);

    if (cin.fail())
        return -1;

    cout << countWords(str8) << endl;




    return 0;
}