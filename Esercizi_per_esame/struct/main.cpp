#include <iostream>
using namespace std;

struct intv {
    int inf;
    int sup;
};

bool add(intv &i, int x) {

    if (x >= i.inf && x <= i.sup) {
        cout << "Valore x aggiunto all'intervallo" << endl;
        return true;
    }
    if (x == i.inf - 1) {
        cout << "Estremo inferiore dell'intervllo modificato" << endl;
        i.inf = x;
        return true;
    }
    if (x == i.sup + 1) {
        cout << "Estremo superiore dell'intervllo modificato" << endl;
        i.sup = x;
        return true;
    }

    cout << "Valore non compreso tra l'intervallo..." << endl;

    return false;

}

int main() {

    intv i;
    i.inf = 3;
    i.sup = 7;

    cout << add(i, 2) << endl;

    cout << "Intervallo: " << "[" << i.inf << ", " <<  i.sup << "]" << endl;
    return 0;
}