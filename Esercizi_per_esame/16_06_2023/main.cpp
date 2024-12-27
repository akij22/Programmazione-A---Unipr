#include <iostream>
using namespace std;



int getDim(char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}

char* noVowels(char* str) {

    char* newS = new char[getDim(str) + 1];

    if (str[0] == '\0')
        return newS;

    strcpy(newS, str);
    newS[getDim(str) + 1] = '\0';

    for (int i = 0; newS[i] != '\0'; i++) {
        if (newS[i] == 'a' || newS[i] == 'e' || newS[i] == 'i' || newS[i] == 'o' || newS[i] == 'u'
        || newS[i] == 'A' || newS[i] == 'E' || newS[i] == 'I' || newS[i] == 'O' || newS[i] == 'U') {

            for (int j = i; newS[j] != '\0'; j++)
                newS[j] = newS[j + 1];

            i = 0;
        }

    }


    return newS;
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