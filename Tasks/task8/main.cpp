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
    bool check = false;

    while (list->next != nullptr) {
        // cout << list->next->data << "VS" << list->data << endl;
        if (list->next->data > list->data) {
            check = true;
            if (count == 0)
                firstNode = list;
            count++;
        } else {
            check = false;
            firstNode = nullptr;
        }
        list = list->next;
    }


    firstNode != nullptr ? cout << "Nodo di partenza della successione: " << firstNode->data << endl : cout << "Il nodo e' null!" << endl;
    (check) ? cout << "La successione e' valida!" << endl : cout << "La successione non e' valida..." << endl;

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

    // aggiungiInCoda(list, 1);

    printIt(list);

    node* finalList = findSuccession(list);

    printIt(finalList);

    printIt(list);

    // Deallocazione della lista
    deleteEntireListIt(list);

    return 0;
}