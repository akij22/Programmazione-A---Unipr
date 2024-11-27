#include <iostream>
using namespace std;

int main() {
    char a, b, c;

    cout << "Inserisci 3 caratteri minuscoli: ";

    // Inserimento dei caratteri in input
    cin >> a >> b >> c;

    // Controllo per la variabile a
    if (a >= 'a' && a <= 'z')
        if (a <= 'm')
            a += 13;
        else
            a -= 13;
    else
        a = '?';

    // Controllo per la variabile b
    if (b >= 'a' && b <= 'z')
        if (b <= 'm')
            b += 13;
        else
            b -= 13;
    else
        b = '?';

    // Controllo per la variabile c
    if (c >= 'a' && c <= 'z')
        if (c <= 'm')
            c += 13;
        else
            c -= 13;
    else
        c = '?';

    // Stampo i caratteri cifrati
    cout << "R0T13: " << a << " " << b << " " << c << endl;

    return 0;
}
