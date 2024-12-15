#include <iostream>
using namespace std;

struct node {
    int dato;
    node* next;
};


void addOnTail(node* &list, int dato) {

    node* newNode = new node;
    newNode->dato = dato;

    if (list == nullptr) {
        newNode->next = list;
        list = newNode;
        return;
    }

    node* cursor = list;
    while (cursor->next != nullptr) {
        cursor = cursor->next;
    }

    cursor->next = newNode;
    newNode->next = nullptr;
}


void printList(node* list) {
    if (list == nullptr) {
        cout << "Lista vuota!" << endl;
        return;
    }

    while (list != nullptr) {
        cout << list->dato << " ";
        list = list->next;
    }
    cout << endl;
}


bool contains(node* list, int dato) {
    bool found = false;

    if (list == nullptr)
        return found;

    while (list != nullptr) {
        if (list->dato == dato)
            found = true;
        list = list->next;
    }
    return found;
}


node* unionList(node* list1, node* list2) {

    node* newList = nullptr;

    if (list1 == nullptr && list2 == nullptr) {
        cout << "Le due liste sono vuote!" << endl;
        return newList;
    }

    if (list1 != nullptr) {
        while (list1 != nullptr) {
            if (!contains(newList, list1->dato)) {
                addOnTail(newList, list1->dato);
            }
            list1 = list1->next;
        }
    }

    if (list2 != nullptr) {
        while (list2 != nullptr) {
            if (!contains(newList, list2->dato)) {
                addOnTail(newList, list2->dato);
            }
            list2 = list2->next;
        }
    }

    return newList;
}

void rotate(node* &list) {
    if (list == nullptr)
        return;

    node* prev = nullptr;
    node* cursor = list;

    while (cursor->next != nullptr) {
        prev = cursor;
        cursor = cursor->next;
    }

    cursor->next = list;
    list = cursor;
    prev->next = nullptr;
}



void reverse (int a[], int dim) {

    int* a2 = new int [dim];
    int j = 0;

    for (int i = dim - 1; i >= 0; i--) {
        if (a[i] != 0) {
            a2[j] = a[i];
            j++;
        }
    }

    for (int i = 0; i < dim; i++) {
        a[i] = a2[i];
    }
    delete[] a2;
}

int getDimString(char* string) {
    int count = 0;
    for (int i = 0; string[i] != '\0'; i++)
        count++;

    return count;
}


char* trim(char* str, char c) {
    int dim = getDimString(str);
    char* newS = new char[dim + 1];

    strcpy (newS, str);
    for (int i = 0; newS[i] != '\0'; i++) {
        if (newS[i] == c) {
            for (int j = i; newS[j] != '\0'; j++) {
                newS[j] = newS[j+1];
            }
            i = 0;
        }

    }

    newS[dim] = '\0';
    return newS;
}

int main() {


    node* list1 = nullptr;
    node* list2 = nullptr;

    addOnTail(list1, 1);
    addOnTail(list1, 2);
    addOnTail(list1, 2);
    addOnTail(list1, 7);

    addOnTail(list2, 1);
    addOnTail(list2, 3);
    addOnTail(list2, 5);

    printList(list1);
    printList(list2);

    node* newList = unionList(list1, list2);

    printList(newList);

    rotate(newList);

    printList(newList);

    cout << endl << "Array" << endl;

    int array[50] = {1, 2, 3, 4, 5};
    char string[101];

    reverse(array, 50);

    for (int i = 0; i < 50; i++) {
        if (array[i] != 0)
            cout << array[i] << " ";
    }

    cout << endl;

    cout << "Inserisci stringa: ";
    cin.getline(string, 100, '\n');

    char* newS = trim(string, 'c');

    cout << newS << endl;

    delete[] newS;


    return 0;
}