#include <iostream>
using namespace std;

// Scrivere una funzione che prende in input una lista e un indice i e rimuova dalla lista l’elemento in posizione i.


struct node {
    int dato;
    node* next;
};


void printList (node* list) {
    if (list != nullptr) {

        while (list != nullptr) {
            cout << list->dato << " ";
            list = list->next;
        }
    }
    cout << endl;
}


void addOnHead (node* list){}

void addOnTail (node* list){}

int main() {


    node* list1 = nullptr;





    return 0;
}