// Name         : OrderedLinkedList.h
// Author       : Kevin Tran
// Version      : 1.03 fixes the insert, delete, and search functions.
// Description  : OrderedLinkedList.h class extends upon LinkedList but
// optimized to insert, delete, and search in a quicker fashion due to List
// being alphabetically organized (ascending and in cases from top -> down).

#ifndef AIRLINEDB_ORDEREDLINKEDLIST_H
#define AIRLINEDB_ORDEREDLINKEDLIST_H

#include "LinkedList.h"
using namespace std;

template <class T>
class OrderedLinkedList:public LinkedList<T>{
public:
    void inserFirst(T&);
    void inserLast(T&);
    void insert(T&);
    T& search(T&);
    void deleteNote(T&);
};

//overridden insertFirst method adds node only one way and so will go to the
//OrderdLinkedList insert method...
template <class T>
void OrderedLinkedList<T>::inserFirst(T& item){
    insert(item);
}

//overridden insertLast method adds node only one way and so will go to the
//OrderdLinkedList insert method...
template <class T>
void OrderedLinkedList<T>::inserLast(T& item){
    insert(item);
}

//overridden search method searches for an item similarly to LinkedLists'
//search except...
template <class T>
T& OrderedLinkedList<T>::search(T& target) {
    if (!this->isEmpty()) {
        node<T> *temp = this->head;
        for (int i=0; i<this->count; i++) {

            //made it more efficient by quitting traversal early when the last
            //name is going to search into something that is going to make it
            //not in ascending order
            if (target == temp->data) {
                return temp->data;
            }else if(target > temp->data){
                temp = temp->next;
            }else{
                break;
            }
        }
        cout << "Item not found in OrderedLinkedList" << endl;
    }else{
        cout << "OrderedLinkedList is empty. " << endl;
    }

    //create a temporary blank node t to return a T item that is blank (default
    //constructor).
    node<T> *t = new node<T>();
    return t->data;
}

//overridden insert method deletes node similarly to LinkedList's deleteNote
//except...
template <class T>
void OrderedLinkedList<T>::insert(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    if(this->head==NULL || this->head->data>item) {
        temp->next = this->head;
        this->head = temp;
        if (this->last == NULL) {
            this->last = temp;
        }
    }else if(this->count==1) {
        if(this->head->data>item){
            temp->next=this->head;
            this->head=temp;
        }else{
            this->head->next = temp;
            this->last = temp;
        }
    }else{

        //Traverse nodes that take not of the current and before current
        //positions. Starts the current position at head.
        node<T> *traverse = this->head->next;
        node<T> *traverseb4 = this->head;

        //traversal will end (at max), at the last node of the
        //OrderedLinkedList.
        while(traverse!=NULL && item>traverse->data || item==traverse->data){
            traverseb4=traverse;
            traverse=traverse->next;
        }
        temp->next=traverse;
        traverseb4->next=temp;
    }
    this->count++;
}

//overridden deleteNote method deletes node similarly to LinkedList's deleteNote
//except...
template <class T>
void OrderedLinkedList<T>::deleteNote(T& item){
    if(this->isEmpty()) {
        cout << "List is empty";
    }else{
        if(this->head->data == item) {
            node<T> *p = this->head;
            this->head = this->head->next;
            delete p;
            this->count--;
            if (this->head == NULL) {
                this->last = NULL;
            }
        }else{

            //Traverse nodes that take not of the current and before current
            //positions. Starts the current position at head's next.
            node<T> *traverse = this->head->next;
            node<T> *traverseb4 = this->head;

            //made it more efficient by quitting traversal early when the last
            //name is going to search into something
            //that is going to make it not in ascending order
            while (traverse != NULL && item > traverse->data) {
                traverseb4 = traverse;
                traverse = traverse->next;
            }

            if (traverse->data == item) {
                traverseb4->next = traverse->next;
                this->count--;
                if (traverse->next  == this->last) {
                    this->last = traverseb4;
                }
                delete traverse;
            } else {
                cout << "Target was not found. Nothing deleted. " << endl;
            }

        }
    }
}

#endif //AIRLINEDB_ORDEREDLINKEDLIST_H
