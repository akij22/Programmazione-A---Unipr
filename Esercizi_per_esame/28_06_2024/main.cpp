#include <iostream>
using namespace std;

struct node {
    int dato;
    node* next;
};


int find_longest_word_lenght(char* sentence) {
    if (sentence[0] == '\0')
        return 0;

    int maxLen = 0;
    int currentCount = 0;

    for (int i = 0; sentence[i] != '\0'; i++) {
        currentCount = 0;
        while (sentence[i] != ' ' && sentence[i] != '\0') {
            currentCount++;
            i++;
        }

        if (currentCount >= maxLen)
            maxLen = currentCount;
    }

    return maxLen;
}

int getDim (char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}


char* replace_spaces(char* str) {
    char* newS = new char[getDim(str) + 1];

    if (str[0] == '\0')
        return newS;

    strcpy(newS, str);
    newS[getDim(str)] = '\0';

    for (int i = 0; newS[i] != '\0'; i++) {
        if (newS[i] == ' ')
            newS[i] = '_';
    }
    return newS;
}

void addOnTail (node* &list, int dato) {
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


node* sum_lists(node* list1, node* list2) {
    if (list1 == nullptr && list2 == nullptr)
        return nullptr;

    node* finalList = nullptr;

    while (list1 != nullptr || list2 != nullptr) {
        if (list1 != nullptr && list2 != nullptr) {
            addOnTail(finalList, list1->dato + list2->dato);
            list1 = list1->next;
            list2 = list2->next;
        } else if (list1 != nullptr) {
            addOnTail(finalList, list1->dato);
            list1 = list1->next;

        } else if (list2 != nullptr) {
            addOnTail(finalList, list2->dato);
            list2 = list2->next;
        }

    }

    return finalList;
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
}

int main() {

    char string[100];

    cout << "Inserisci stringa: ";
    cin.getline(string, 99);

    cout << find_longest_word_lenght(string) << endl;

    char string2[101];

    cout << "Inserisci stringa: ";
    cin.getline(string2, 100);

    if (cin.fail())
        return -1;

    char* newS = replace_spaces(string2);

    cout << newS << endl;

    delete [] newS;

    cout << endl << endl;

    node* list1 = nullptr;
    node* list2 = nullptr;

    addOnTail(list1, 1);
    addOnTail(list1, 2);
    addOnTail(list1, 3);
    addOnTail(list1, 7);

    addOnTail(list2, 4);
    addOnTail(list2, 5);
    addOnTail(list2, 6);


    node* finalList = sum_lists(list1, list2);

    printList(finalList);

    return 0;
}