#include <iostream>
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

// Versione iterativa
node* firstEven(node* list) {
    if (list == nullptr)
        return nullptr;

    while (list != nullptr) {
        if (list->data % 2 == 0)
            return list;
        list = list->next;
    }
    return nullptr;
}

// Versione ricorsiva
node* firstEven_rec(node* list) {
    if (list == nullptr)
        return nullptr;

    if (list->data % 2 == 0)
        return list;
    else return firstEven_rec(list->next);
}

int main() {

    node* list1 = nullptr;

    addOnTail(list1, 5);
    addOnTail(list1, 7);
    addOnTail(list1, 2);
    addOnTail(list1, 8);
    addOnTail(list1, 4);
    addOnTail(list1, 11);

    cout << "Versione iterativa" << endl;
    node* final = firstEven(list1);

    cout << final->data << endl;

    cout << "Versione ricorsiva" << endl;

    final = firstEven_rec(list1);
    cout << final->data;
    return 0;
}