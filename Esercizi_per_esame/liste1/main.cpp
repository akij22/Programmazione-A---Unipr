#include <iostream>
#include <list>
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


void addOnHead (node* &list, int dato) {

    node* new_node = new node;
    new_node->dato = dato;

    new_node->next = list;

    // La testa dienta il nuovo nodo
    list = new_node;


}

void addOnTail (node* &list, int dato) {

    if (list == nullptr) {
        addOnHead(list, dato);
        return;
    }

    node* cursor = list;
    while (cursor->next != nullptr)
        cursor = cursor->next;

    node* last = new node;
    last->dato = dato;
    cursor->next = last;
    last->next = nullptr;

}


void rimuoviByIndice(node* &list, int indice) {

    if (list == nullptr) {
        cout << "La lista è vuota!" << endl;
        return;
    }

    int c = 1;
    indice = indice - 1;
    node* cursor = list;

    while (c != indice) {
        cursor = cursor->next;
        c++;
    }

    node* toDelete = cursor->next;
    cursor->next = cursor->next->next;

    delete toDelete;

}

int main() {


    node* list1 = nullptr;

    addOnHead(list1, 10);
    addOnHead(list1, 9);
    addOnHead(list1, 8);
    addOnTail(list1, 99);


    printList(list1);

    rimuoviByIndice(list1, 3);
    cout << endl;

    printList(list1);




    return 0;
}