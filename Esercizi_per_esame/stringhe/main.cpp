#include <iostream>
using  namespace std;
#include <cstring>

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


int main() {

    // Lunghezza max della stringa = 100
    char str1[101], str2[101];


    cout << "Inserire la prima parola: ";
    cin.getline(str1, 100);

    cout << "Inserire la seconda parola: ";
    cin.getline(str2, 100);

    if (findSubString(str1, str2))
        cout << "Esistono sottostringhe" << endl;
    else
        cout << "Non esistono sottostringhe" << endl;



    return 0;
}