#include <iostream>
using namespace std;


struct node {
    int dato;
    node* next;
};


void shift_left(int arr[], int n, int k) {
    int backup = 0;

    for (int i = 0; k < n; i++) {
        if (i != 0)
            k = k + 1;
        arr[i] = arr[k];
        backup = i;
    }

    backup+= 1;

    for (int i = 0; backup < n; i++) {
        arr[backup] = 0;
        backup++;
    }
}

void printArray(int arr[], int dim) {
    for (int i = 0; i < dim; i++)
        cout << arr[i] << " ";
    cout << endl;
}


int getDim(char* str) {
    int count = 0;

    for (int i = 0; str[i] != '\0'; i++)
        count++;

    return count;
}

char* interleave(char* str1, char* str2) {
    char* newS = new char[(getDim(str1) * 2) + 1];

    if (str1[0] == '\0' && str2[0] == '\0')
        return newS;

    int j = 0;

    for (int i = 0; str1[i] != '\0'; i++) {
        newS[j] = str1[i];
        j+= 1;
        newS[j] = str2[i];
        j+=1;
    }

    newS[j] = '\0';
    return newS;
}

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

void rotate_back(node* &list) {

    if (list == nullptr)
        return;

    node* cursor1 = list->next;
    node* cursor2 = list;
    node* cursor3 = list;

    while (cursor2->next != nullptr)
        cursor2 = cursor2->next;

    cursor2->next = list;
    list->next = nullptr;
    //cursor3->next = nullptr;

    list = cursor1;

}

void rotate (node* &list) {
    if (list == nullptr)
        return;

    node* cursor = list;
    node* nxt = nullptr;
    node* prev = nullptr;

    while (cursor != nullptr) {
        nxt = cursor->next;
        cursor->next = prev;
        prev = cursor;
        cursor = nxt;
    }

    list = prev;
}


int main() {

    char s1[101] = {'c', 'i', 'a', 'o', '\0'};
    char s2[101] = {'1', '2', '3', '4', '\0'};

    int arr[5] = {1, 2, 3, 4, 5};

    shift_left(arr, 5, 2);

    printArray(arr, 5);


    if (getDim(s1) != getDim(s2))
        return -1;

    char* s3 = interleave(s1, s2);

    cout << s3 << endl;

    char s =  *(s3+8);

    delete [] s3;

    node* list1 = nullptr;
    addOnTail(list1, 1);
    addOnTail(list1, 2);
    addOnTail(list1, 3);
    addOnTail(list1, 4);
    addOnTail(list1, 5);

    rotate_back(list1);

    printList(list1);

    rotate(list1);

    printList(list1);



    return 0;
}