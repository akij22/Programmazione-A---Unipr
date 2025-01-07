#include <iostream>
using namespace std;

void removeDuoplicates_inPlace(char* &str) {
    if (str[0] == '\0')
        return;

    bool found = false;

    for (int i = 0; str[i] != '\0'; i++) {
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[i] == str[j] && found == true) {
                for (int k = j; str[k] != '\0'; k++)
                    str[k] = str[k+1];
                i = 0;
            } else if (str[i] == str[j] && found == false)
                found = true;
        }
        found = false;
    }
}




int main() {

    char str[100] = {'c', 'c', 'c' , 'i', 'i', 'a', 'c', 'o', 'c', '\0'};

    char* str2 = new char[100];

    strcpy(str2, str);

    cout << str2 << endl;

    removeDuoplicates_inPlace(str2);

    cout << str2 << endl;

    delete str2;
    return 0;
}