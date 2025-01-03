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


void concat (node* list1, node* list2) {
    if (list1 == nullptr && list2 == nullptr)
        return;

    while (list2 != nullptr) {
        addOnTail(list1, list2->data);
        list2 = list2->next;
    }
}

bool isDescending (node* list) {
    bool check = true;

    if (list == nullptr)
        return false;

    while (list->next != nullptr) {
        if (list->data > list->next->data && check == true)
            check = true;
        else
            check = false;

        list = list->next;
    }

    return check;
}

bool equals(node* list1, node* list2) {
    if (list1 == nullptr && list2 == nullptr) {
        return true;
    }

    if (list1->data != list2->data)
        return false;

    return equals(list1->next, list2->next);
}

// Rotazione della lista di un elemento
void rotate_back(node* &list) {
    if (list == nullptr)
        return;

    node* newList = list->next;
    node* cursor = list;

    while (cursor->next != nullptr)
        cursor = cursor->next;

    cursor->next = list;
    list->next = nullptr;
    list = newList;
}


void rotate_back_n_times(node* &list, int n) {
    if (list == nullptr)
        return;

    for (int i = 0; i < n; i++) {
        node* newList = list->next;
        node* cursor = list;

        while (cursor->next != nullptr)
            cursor = cursor->next;

        cursor->next = list;
        list->next = nullptr;
        list = newList;
    }
}


void bubbleSort(node* list) {
    if (list == nullptr || list->next == nullptr)
        return;


    bool swapped;
    do {
        swapped = false;
        node* cursor = list;

        while (cursor->next != nullptr) {
            if (cursor->data > cursor->next->data) {

                int temp = cursor->data;
                cursor->data = cursor->next->data;
                cursor->next->data = temp;
                swapped = true;
            }
            cursor = cursor->next;
        }
    } while (swapped);
}

void insertNodeByIndice (node* &list, int value, int indice) {
    node* cursor = list;
    if (list == nullptr)
        return;

    int i = 0;
    while (i != indice) {
        cursor = cursor->next;
        i++;
    }

    node* newNode = new node;
    newNode->data = value;
    node* next = cursor->next;
    cursor->next = newNode;
    newNode->next = next;
}

void removeHead(node* &list) {
    if (list == nullptr)
        return;

    node* toDelete = list;
    list = list->next;
    delete toDelete;
}


int main() {


    node* list1 = nullptr;
    node* list2 = nullptr;

    node* list3 = nullptr;
    node* list4 = nullptr;
    node* list5 = nullptr;
    node* list6 = nullptr;
    node* list7 = nullptr;

    addOnTail(list3, 12);
    addOnTail(list3, 3);
    addOnTail(list3, -5);
    addOnTail(list3, -7);

    addOnTail(list1, 10);
    addOnTail(list1, 20);
    addOnTail(list1, 30);
    addOnTail(list1, 40);
    addOnTail(list1, 50);

    addOnTail(list2, 2);
    addOnTail(list2, 4);
    addOnTail(list2, 6);

    addOnTail(list4, 2);
    addOnTail(list4, 4);
    addOnTail(list4, 6);

    addOnTail(list5, 1);
    addOnTail(list5, 2);
    addOnTail(list5, 3);
    addOnTail(list5, 4);
    addOnTail(list5, 5);

    addOnTail(list6, 1);
    addOnTail(list6, 2);
    addOnTail(list6, 3);
    addOnTail(list6, 4);
    addOnTail(list6, 5);

    addOnTail(list7, 5);
    addOnTail(list7, 4);
    addOnTail(list7, 3);
    addOnTail(list7, 2);
    addOnTail(list7, 1);

    printList(list1);
    printList(list2);

    node* new_list = concatena(list1, list2);

    printList(new_list);


    node* sumList = sommaVicini(list1);

    printList(sumList);



    concat(list1, list2);
    cout << "Lista 1: ";
    printList(list1);

    cout << "Lista 2: ";
    printList(list2);

    bool desc = isDescending(list3);

    cout << endl;
    cout << desc << endl;

    cout << equals(list2, list4);


    // Deallocazione delle liste
    deleteEntireList(list1);
    deleteEntireList(list2);
    deleteEntireList(list3);

    rotate_back(list5);
    cout << endl << "Lista 5:" << endl;
    printList(list5);


    rotate_back_n_times(list6, 2);
    cout << endl << "Lista 6:" << endl;
    printList(list6);


    bubbleSort(list7);

    cout << "LISTA 7" << endl;
    printList(list7);

    insertNodeByIndice(list7, 99, 2);

    printList(list7);

    removeHead(list7);
    printList(list7);




    return 0;
}