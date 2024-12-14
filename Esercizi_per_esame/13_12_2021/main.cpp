#include <iostream>
#include <list>
using namespace std;

/*
 *
* Scrivere una funzione di nome coincide che, presi come suoi parametri due 13_12_2021 di interi a1 ed
  a2 e le loro dimensioni d1 e d2, determina e restituisce come risultato il numero di elementi coincidenti in a1 e a2: un
  elemento e1 di a1 ed un elemento e2 di a2 si dicono coincidenti se hanno lo stesso indice e lo stesso valore. Per esempio,
  se a1 = {7,6,4,-1,2,5,12} e a2 = {6,7,4,5,2}, la funzione coincide deve ritornare 2
 *\
 */


struct node {
    int data;
    node* next;
};





int coincideArray (int a1[], int a2[], int dim1, int dim2) {

    int i = 0, j = 0;
    int count = 0;

    while (i < dim1 && j < dim2) {

        if (a1[i] == a2[j] && i == j)
            count++;


        i++;
        j++;
    }

    return count;
}


/*
 *
* Esercizio 3 (15pt). Scrivere una funzione di tipo void di nome concat che, presi come suoi parametri due liste
  concatenate semplici l1 ed l2 i cui elementi hanno campo informazione di tipo int, concateni la lista l2 alla lista l1. Ad
  esempio, se l1 = {1,7} e l2 = {5,9,12}, dopo la chiamata alla funzione concat passando come parametri l1 ed l2, la
  lista l1 diventa {1,7,5,9,12}. Trattare in modo opportuno anche i casi in cui l1 e/o l2 siano liste vuote. (+3pt se la
  funzione `e ricorsiva)
 *
 */

void addOnTail (node* &list, int dato) {

    if (list == nullptr) {
        node* newNode = new node;
        newNode->data = dato;

        newNode ->next = list;
        list = newNode;

    } else {

        node* support = list;
        while (support->next != nullptr) {
            support = support -> next;
        }

        node* newNode = new node;
        newNode->data = dato;


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
    cout << list->data << " ";
        list = list->next;
    }

    cout << endl;

}


void concat (node* list1, node* list2, node* &newList) {

    if (list1 == nullptr && list2 == nullptr) {
        cout << "Le liste sono vuote!" << endl;
        return;
    }


    // Aggiunta del dato per la prima lista
    while (list1 != nullptr) {
        addOnTail(newList, list1->data);
        list1 = list1->next;
    }

    // Aggiunta del dato per la seconda lista
    while (list2 != nullptr) {
        addOnTail(newList, list2->data);
        list2 = list2->next;
    }
}





int main() {
    int array1[] = {7, 6, 4, -1, 2, 5, 12};
    int array2[] = {6, 7, 4, 5, 2};

    int count = coincideArray(array1, array2, 7, 5);

    cout << endl << "OUTPUT PRIMO ESERCIZIO" << endl;
    cout << "Il numero restituito dalla funzione e' " << count << endl << endl;;


    cout << "OUTPUT SECONDO ESERCIZIO" << endl;

    node* list1 = nullptr;
    node* list2 = nullptr;

    addOnTail(list1, 10);
    addOnTail(list2, 20);
    addOnTail(list1, 30);
    addOnTail(list2, 40);

    cout << "Prima lista: ";
    printList(list1);
    cout << "Seconda lista: ";
    printList(list2);

    node* finalList = nullptr;

    concat(list1, list2, finalList);

    cout << "Lista concatenata: ";
    printList(finalList);


    return 0;
}