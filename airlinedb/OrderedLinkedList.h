// Name         : OrderedLinkedList.h
// Author       : Kevin Tran
// Description  : OrderedLinkedList.h class extends upon LinkedList but optimized to insert, delete, and search in a
// quicker fashion due to List being alphabetically organized (ascending and in cases from top -> down).

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

//overridden insertFirst method adds node only one way and so will go to the OrderdLinkedList insert method...
template <class T>
void OrderedLinkedList<T>::inserFirst(T& item){
    insert(item);
}

//overridden insertLast method adds node only one way and so will go to the OrderdLinkedList insert method...
template <class T>
void OrderedLinkedList<T>::inserLast(T& item){
    insert(item);
}

//overridden search method searches for an item similarly to LinkedLists' search except...
template <class T>
T& OrderedLinkedList<T>::search(T& target){
    node <T> *temp = this->head;
    while(temp!=NULL){

        //made it more efficient by quitting traversal early when the last name is going to search into something
        //that is going to make it not in ascending order
        if(target==temp->data && target>temp->data){
            return temp->data;
        }
        temp = temp -> next;
    }
    cout<<"Item not found in OrderedLinkedList"<<endl;
}

//overridden insert method deletes node similarly to LinkedList's deleteNote except...
template <class T>
void OrderedLinkedList<T>::insert(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    node<T> *traverse = this->head;
    node<T> *traverseb4;
    if(this->head==NULL){
        this->head=this->last=temp;
    }else{
        while(traverse!=NULL && item>traverse->data){
            traverseb4=traverse;
            traverse=traverse->next;
        }
        if(traverse==this->head && this->head->next!=NULL) {
            temp->next = this->head;
            this->head = temp;
        }else {
            traverseb4->next = temp;
            temp->next = traverse;
            if (&traverse == NULL) {
                this->last = traverseb4->next;
            }
        }
    }
    this->count++;
}

//overridden deleteNote method deletes node similarly to LinkedList's deleteNote except...
template <class T>
void OrderedLinkedList<T>::deleteNote(T& item){
    if(this->head == NULL)
        cout<<"List is empty";
    else{
        if(this->head->data == item) {
            node<T> *p = this->head;
            this->head = this->head->next;
            delete p;
            this->count--;
            if (this->head == NULL) {
                this->last = NULL;
            }
        }else{
            node<T>* p = this->head;
            node<T>* q = p->next;

            //made it more efficient by quitting traversal early when the last name is going to search into something
            //that is going to make it not in ascending order
            while(q!=NULL && q->data != item && item>q->data){
                p = q;
                q = q->next;
            }
            if(q!=NULL){
                p->next = q->next;
                this->count--;
                if(this->last == q){
                    this->last = p;
                }
                delete q;
            }else{
                cout<<"Target was not found. Nothing deleted. "<<endl;
            }
        }
    }
}

#endif //AIRLINEDB_ORDEREDLINKEDLIST_H
