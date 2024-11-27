#include <iostream>
using namespace std;

int main() {
    char a, b, c;

    cout << "Inserisci 3 caratteri minuscoli: ";

    // Inserimento dell'utente dei caratteri in input
    cin >> a >> b >> c;

    // Controllo il range di a e gli assegno il carattere corretto
    // Se il carattere è contenuto tra 'a' e 'm', gli sommo 13, altrimenti (se è sempre contenuto nel range) gli sottraggo 13
    // Se non è valido, gli assegno '?'
    a >= 'a' && a <= 'z' ? a <= 'm' ? a += 13 : a -= 13 : a  = '?';
   
    // Controllo il range di b e gli assegno il carattere corretto
    b >= 'a' && b <= 'z' ? b <= 'm' ? b += 13 : b -= 13 : b = '?';
    
    // Controllo il range di c e gli assegno il carattere corretto
    c >= 'a' && c <= 'z' ? c <= 'm' ? c += 13 : c -= 13 : c = '?';

    // Stampo i caratteri cifrati
    cout << "R0T13: " << a << " " << b << " " << c << endl;

    return 0;
}