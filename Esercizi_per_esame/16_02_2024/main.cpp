#include <iostream>
using namespace std;


struct node {
    int dato;
    node* next;
};

void addOnTail (node* &list, int dato) {

    if (list == nullptr) {
        node* newNode = new node;
        newNode->dato = dato;

        newNode ->next = list;
        list = newNode;

    } else {

        node* support = list;
        while (support->next != nullptr) {
            support = support -> next;
        }

        node* newNode = new node;
        newNode->dato = dato;


        support->next = newNode;
        newNode -> next = nullptr;


    }
}


void printList (node* list) {
    if (list == nullptr) {
        cout << "Lista vuota!" << endl;
        return;
    }

    while (list != nullptr){
        cout << list->dato << " ";
        list = list->next;
    }

    cout << endl;

}

int getDim(char* str) {

    if (str[0] == '\0')
        return 0;
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}

char* replace(char* str, char target, char replacement) {
    char* newS = new char[getDim(str)];

    if (str[0] == '\0')
        return newS;

    strcpy(newS, str);

    for (int i = 0; newS[i] != '\0'; i++) {
        if (newS[i] == target)
            newS[i] = replacement;
    }

    return newS;
}


void swap(int a[], int b[], int n) {

    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) {
            int temp = a[i];
            a[i] = b[i];
            b[i] = temp;
        }
    }
}


void rotate (node* &list) {
    if (list == nullptr)
        return;

    node* cursor = list;
    node* prev = nullptr;

    while (cursor->next != nullptr) {
        prev = cursor;
        cursor = cursor ->next;
    }

    cursor->next= list;
    prev->next = nullptr;
    list = cursor;

}


int main() {

    char string[101];

    int a[5] = {1, 6, 2, 2, 4};
    int b[5] = {3, 4, 5, 4, 1};
    swap(a, b, 5);

    for (int i = 0; i < 5; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    cout << "Inserisci stringa: ";
    cin.getline(string, 100);

    if (cin.fail())
        return -1;

    char* newS = replace(string, 'a', 'e');

    cout << newS;

    delete [] newS;

    node* list1 = nullptr;

    addOnTail(list1, 1);
    addOnTail(list1, 2);
    addOnTail(list1, 3);
    addOnTail(list1, 4);
    addOnTail(list1, 5);

    cout << endl;
    rotate(list1);

    printList(list1);




    return 0;
}