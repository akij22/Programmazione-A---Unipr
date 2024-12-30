#include <iostream>
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
    node* cursor = nullptr;
    while (cursor2 != nullptr) {
        int currentDato = cursor2->dato;
        int check = 0;

        // Resetto il secondo puntatore
        // Ad ogni conclusione di ciclo for riparto dalla testa
        cursor = list;

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


char* remove_double(char* str) {
    char* newS = new char[getLen(str)];

    newS[getLen(str)] = '\0';

    bool found = false;
    bool removed = false;

    strcpy(newS, str);

    for (int i = 0; newS[i] != '\0'; i++) {
        for (int j = 0; newS[j] != '\0'; j++){
            if (newS[i] == newS[j] && found == true) {
                for (int k = j; newS[k] != '\0'; k++)
                    newS[k] = newS[k+1];
            } else if (newS[i] == newS[j] && found == false) {
                found = true;
            }
        }
        found = false;
    }

    return newS;
}

void removeDuplicatesInPlace(char* &str) {

    if (str[0] == '\0')
        return;

    for (int i = 0; str[i] != '\0'; i++) {
        bool found = false;
        for (int j = 0; str[j] != '\0'; j++) {
            if (str[i] == str[j] && found) {
                for (int k = j; str[k] != '\0'; k++)
                    str[k] = str[k+1];
                j = 0;
                found = false;

            } else if (str[i] == str[j] && !found)
                found = true;
        }
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


    // Da fare parte di inserimento chiesta all'utente, ciò e' stato
    // fatto per velocizzare la fase di test
    char string[100] = {'a', 'a', 'b', 'b', 'b', 'c', 'c', 'c'};

    char* newS = remove_double(string);

    cout << newS << endl;

    delete newS;


    char* newS2 = new char[100];
    strcpy(newS2, string);

    removeDuplicatesInPlace(newS2);


    cout << newS2 << endl;
    delete [] newS2;


    return 0;
}
