#include <iostream>
using namespace std;

int find_longest_word_lenght(char* sentence) {
    if (sentence[0] == '\0')
        return 0;

    int maxLen = 0;
    int currentCount = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        currentCount = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            currentCount++;
            i++;
        }

        if (currentCount >= maxLen)
            maxLen = currentCount;
    }

    return maxLen;
}

int getDim (char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}


char* replace_spaces(char* str) {
    char* newS = new char[getDim(str)];

    if (str[0] == '\0')
        return newS;

    strcpy(newS, str);
    newS[getDim(str)] = '\0';

    for (int i = 0; newS[i] != '\0'; i++) {
        if (newS[i] == ' ')
            newS[i] = '_';
    }
    return newS;
}

int main() {

    char string[100];

    cout << "Inserisci stringa: ";
    cin.getline(string, 99);

    cout << find_longest_word_lenght(string) << endl;

    char string2[101];

    cout << "Inserisci stringa: ";
    cin.getline(string2, 100);

    if (cin.fail())
        return -1;

    char* newS = replace_spaces(string2);

    cout << newS << endl;

    delete [] newS;


    return 0;
}