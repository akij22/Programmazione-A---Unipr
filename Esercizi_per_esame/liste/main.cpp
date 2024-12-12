#include <iostream>
#include <list>
using namespace std;


struct node {
    int data;
    node* next;
};

void addOnTail (node* &list, int dato) {
    if (list == nullptr) {
        node* new_node = new node;
        new_node->data = dato;
        new_node->next = list;
        list = new_node;
        return;

    }

    node* cursor = list;

    while (cursor->next != nullptr) {
        cursor = cursor->next;
    }
    node* last = new node;
    last->data = dato;
    cursor->next = last;
    last->next = nullptr;


}


void printList (node* list1) {

    if (list1 == nullptr)
        cout << "Lista vuota!" << endl;
    else {
        while (list1 != nullptr) {
            cout << list1->data << " ";
            list1 = list1->next;
        }
    }
    cout << endl;
}


/*
Scrivi una funzione che prenda due liste concatenate come input e le intervalli (ovvero, mescoli i
nodi alternando i nodi della prima e della seconda lista), restituendo una nuova lista concatenata. Se una lista
è più lunga dell'altra, i nodi rimanenti della lista più lunga devono essere aggiunti alla fine della lista risultante.
Per esempio, se le due liste sono 1-> 3 ->5 e 2 -> 4 ->6, la funzione dovrà ritornare la lista 1 -> 2 -> 3 -> 4 -> 5 -> 6.
 */

node* concatena (node* list1, node* list2) {

    node* returnList = nullptr;

    while (list1 != nullptr || list2 != nullptr) {

        if (list1 != nullptr) {
            addOnTail(returnList, list1->data);
            list1 = list1->next;
        }

        if (list2 != nullptr) {
            addOnTail(returnList, list2->data);
            list2 = list2->next;
        }

    }



    return returnList;
}



/*
 *Scrivere una funzione che, data una lista semplicemente concatenata,
 *restituisca una nuova lista dove ogni nodo contiene la somma dei suoi vicini,
 *lasciando la lista originale invariata. Per il primo e l'ultimo nodo (che non hanno entrambi i vicini),
 *il loro valore rimarrà invariato nella nuova lista. Per esempio se la lista presa come parametro è 10 -> 20 -> 30 -> 40 ->50, la
 *funzione dovrà ritornare la lista 10 -> 40 -> 60 -> 80 -> 50.
 */

node* sommaVicini (node* list) {

    node* sumList = nullptr;

    if (list == nullptr) {
        cout << "La lista è vuota" << endl;
        return nullptr;
    }

    int check = 0;
    node* previous = nullptr;

    while (list != nullptr) {

        if (check == 0 || list->next == nullptr) {

            addOnTail(sumList, list->data);

            if (check == 0)
                previous = list;

        } else {
            addOnTail(sumList, previous->data + list->next->data);
            previous = list;

        }

        check++;
        list = list->next;
    }

    return sumList;
}


// Rimozione di un elemento, dando un indice come input
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


void deleteEntireList (node* &list1) {

    while (list1 != nullptr) {
        node* temp = list1;
        list1 = list1->next;
        delete temp;
    }
}


int main() {


    node* list1 = nullptr;
    node* list2 = nullptr;

    addOnTail(list1, 10);
    addOnTail(list1, 20);
    addOnTail(list1, 30);
    addOnTail(list1, 40);
    addOnTail(list1, 50);

    addOnTail(list2, 2);
    addOnTail(list2, 4);
    addOnTail(list2, 6);

    printList(list1);
    printList(list2);

    node* new_list = concatena(list1, list2);

    printList(new_list);


    node* sumList = sommaVicini(list1);

    printList(sumList);



    // Deallocazione delle liste
    deleteEntireList(list1);
    deleteEntireList(list2);


    return 0;
}