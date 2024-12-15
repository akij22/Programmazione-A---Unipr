#include <iostream>
using namespace std;

int countByChar (char* s, char c) {

    int count = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c)
            count++;
    }
    return count;
}


int countUnique(char* s) {

    if (s[0] == '\0') {
        cout << "Stringa vuota!" << endl;
        return 0;
    }

    int unique = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        char temp = s[i];
        if (countByChar(s, temp) == 1)
            unique++;
    }

    return unique;
}

int main() {


    char string[51];

    cout << "Inserire stringa: ";
    cin.getline(string, 50, '\n');

    if (cin.fail())
        return -1;

    cout << countUnique(string) << endl;

    return 0;
}