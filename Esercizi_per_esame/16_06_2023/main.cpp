#include <iostream>
using namespace std;

/*
Scrivere una funzione noVowels che, preso come parametro una stringa C-style str ritorna una nuova stringa
ottenuta eliminando tutte le vocali contenute in str.
Scrivere una funzione main che legge da tastiera una stringa di massimo 50 caratteri, chiama la funzione noVowels
passando come parametro la stringa letta ed infine stampa il risultato ritornato dalla chiamata alla funzione
noVowels. Nel caso in cui la lunghezza della stringa inserita dall’utente sia maggiore di 50 caratteri, la funzione
main deve ritornare -1.
*/


char* noVowels(char string []) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u') {


        } else if (string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U') {


        }
    }


    return string;
}

int main() {

    char s[51];

    cout << "Inserisci stringa: ";
    cin.getline(s, 50, '\n');

    if (cin.fail()) {
        return -1;
    }

    char* sNew = noVowels(s);

    cout << sNew << endl;


    return 0;
}