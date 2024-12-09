#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

void aggiungiInTesta(node* &list, int e) {
    node* new_node = new node;
    new_node->data = e;
    new_node->next = list;
    list = new_node;
}

void aggiungiInCoda(node* &list, int e)  {
    if (list == nullptr)
        aggiungiInTesta(list, e);

    node* new_node = new node;
    new_node->data = e;
    new_node->next = nullptr;

    node* cursor = list;
    while (cursor->next != nullptr)
        cursor = cursor->next;
    cursor->next = new_node;
}


void printIt(node* list) {
    if (list == nullptr)
        cout << "Empty list" << endl;
    else {
        while (list != nullptr) {
            cout << list->data << " ";
            list = list->next;
        }
    }
    cout << endl;
}

node* findSuccession(node* list) {

    node* firstNode = nullptr;

    int count = 0;

    while (list->next != nullptr) {

        if (list->next->data > list->data) {
            if (count == 0)
                firstNode = list;
            count++;
        } else {
            firstNode = nullptr;
            count = 0;
        }
        list = list->next;
    }

    return firstNode;
}


void deleteEntireListIt(node* list) {

    while (list != nullptr) {
        node* temp = list;
        list = list->next;
        delete temp;
    }
}


int main() {

    node* list = nullptr;


    aggiungiInTesta(list, 55);
    aggiungiInTesta(list, 10);
    aggiungiInTesta(list, 2);
    aggiungiInTesta(list, 1);
    aggiungiInTesta(list, 7);


    node* finalList = findSuccession(list);

    cout << "Stampa della lista trovata come successione:" << endl;
    printIt(finalList);

    cout << "Stampa della lista originale:" << endl;
    printIt(list);

    // Deallocazione della lista
    deleteEntireListIt(list);

    return 0;
}