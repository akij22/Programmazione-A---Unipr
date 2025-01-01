#include <iostream>
using namespace std;

struct node {
    int dato;
    node* next;
};

int getSumSequence(int a[], int n, int k) {

    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum = 0;
            for (int k2 = i; k2 <= j; k2++) {
                sum = sum + a[k2];
            }

            if (sum == k)
                count++;
        }
    }
    return count;
}

char* reverseString(char* str) {
    if (str[0] == '\0')
        return nullptr;

    char* newS = new char[strlen(str) + 1];
    int j = strlen(str) - 1;

    for (int i = 0; i < strlen(str); i++) {
        newS[i] = str[j];
        j--;
    }

    newS[strlen(str) + 1] = '\0';

    return newS;
}

void addOnTail(node* &list, int dato) {
    node* newNode = new node;
    newNode->dato = dato;

    if (list == nullptr) {
        newNode->next = list;
        list = newNode;
        return;
    }

    node* cursor = list;
    while (cursor->next != nullptr)
        cursor = cursor->next;

    cursor->next = newNode;
    newNode->next = nullptr;
}

node* greaterThanZero (node* list) {
    if (list == nullptr)
        return nullptr;

    node* newList = nullptr;

    while (list != nullptr) {
        if (list->dato > 0 )
            addOnTail(newList, list->dato);

        list = list->next;
    }

    return newList;
}

void printList (node* list) {
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


int main() {
    int a[7] = {1, 2, -3, 7, -1, 4, 3};

    char string[6] = {'h', 'e', 'l', 'l', 'o', '\0'};

    char* newS = reverseString(string);

    cout << "Numero sottosequenze: " << getSumSequence(a, 7, 3) << endl;

    cout << newS << endl;


    delete [] newS;

    node* list1 = nullptr;

    addOnTail(list1, 1);
    addOnTail(list1, 2);
    addOnTail(list1, -2);
    addOnTail(list1, -3);
    addOnTail(list1, 99);


    printList(list1);

    node* newList = greaterThanZero(list1);

    printList(newList);

    
    return 0;
}