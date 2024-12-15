#include <iostream>
#include <list>
using namespace  std;


struct node {
    int dato;
    node* next;
};



int getLen(char* str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}

void reverseString(char* string) {

    char newStr[100];
    int j = 0;

    for (int i = getLen(string) - 1; i >= 0; i--) {
        newStr[j] = string[i];
        j++;

    }

    newStr[j] = '\0';

    for (int i = 0; i <= getLen(newStr); i++) {
        string[i] = newStr[i];
    }

}



void addOnTail(node* &list, int dato) {
    node* newNode = new node;
    newNode->dato = dato;
    if (list == nullptr) {
        newNode->next = list;
        list = newNode;
    } else {

        node* cursor = list;
        while (cursor->next != nullptr)
            cursor = cursor->next;

        cursor->next = newNode;
        newNode->next = nullptr;
    }
}

void printList (node* list) {
    if (list == nullptr)
        return;

    while (list != nullptr) {
        cout << list->dato << " ";
        list = list->next;
    }

    cout << endl;
}


int getLenList(node* list) {
    int count = 0;
    if (list == nullptr)
        return 0;

    while (list != nullptr) {
        count++;
        list = list->next;
    }
    return count;
}


void removeByIndice(node* &list, int indice) {
    if (list == nullptr) {
        cout << "Lista vuota!" << endl;
        return;
    }

    node* cursor = list;
    int i = 0;
    indice = indice - 1;

    while (i != indice) {
        cursor = cursor->next;
        i++;
    }
    node* toDelete = cursor->next;

    cursor->next = cursor->next->next;

    delete toDelete;


}

void removeDuplicates (node* &list) {
    if (list == nullptr)
        return;

    node* cursor2 = list;

    while (cursor2 != nullptr) {
        int currentDato = cursor2->dato;
        int check = 0;

        node* cursor = list;

        for (int i = 0; i < getLenList(list); i++) {
            bool found = false;
            if (currentDato == cursor->dato && check != 0)
                found = true;


            else if (currentDato == cursor->dato && check == 0)
                check++;


            cursor = cursor->next;
            if (found)
                removeByIndice(list, i);
        }

        cursor2 = cursor2->next;


    }
}


int main() {


    char newString[100];

    cout << "Inserisci stringa: ";
    cin.getline(newString, 99, '\n');

    reverseString(newString);

    cout << newString << endl;


    node* list1 = nullptr;

    addOnTail(list1, 10);
    addOnTail(list1, 10);
    addOnTail(list1, 20);
    addOnTail(list1, 20);
    addOnTail(list1, 30);
    addOnTail(list1, 30);


    printList(list1);





    removeDuplicates(list1);
    printList(list1);

    return 0;
}
