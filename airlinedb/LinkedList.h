// Name         : LinkedList.h
// Author       : Farma Serce
// Modified     : Kevin Tran
// Description  : LinkedList class provided by professor but search function has been added so it can be over-ridden in
// child class OrderedLinkedList.h.

#ifndef AIRLINEDB_LINKEDLIST_H
#define AIRLINEDB_LINKEDLIST_H

#include <iostream>
using namespace std;

//node struct definition to define node.
template <class T>
struct node{
    T data;
    node* next;
};

template <class T>
class LinkedList{
    LinkedList(const LinkedList&)=delete; //copy constructor
protected:
    int count;
    node<T> *head, *last;
public:
    LinkedList();
    bool isEmpty();
    int length();
    T front();
    T back();

    virtual void inserFirst(T&);
    virtual void inserLast(T&);
    virtual void deleteNote(T&);
    void destroylist();
    virtual T& search(T&);
    template <class U>
    friend ostream& operator<<(ostream& os, LinkedList<U>& list);
    ~LinkedList();
};

//Default Constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = last = NULL;
    count = 0;
}

//isEmpty method returns if LinkedList is empty.
template <class T>
bool LinkedList<T>::isEmpty(){
    return head==NULL;
}

//length method returns the number of objects in the LinkedList.
template <class T>
int LinkedList<T>::length(){
    return count;
}

//front method returns the front node's data.
template <class T>
T LinkedList<T>::front(){
    return head->data;
}

//back method returns the back node's data.
template <class T>
T LinkedList<T>::back(){
    return last->data;
}

//inserFront method inserts an item to the front spot in the arrayList.
template <class T>
void LinkedList<T>::inserFirst(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    temp->next = head;
    head = temp;
    count++;
    if(last==NULL) last = temp;

}

//inserLast method inserts an item to the last spot in the arrayList.
template <class T>
void LinkedList<T>::inserLast(T& item){
    node<T> *newnode = new node<T>;
    newnode->data = item;
    newnode->next = NULL;
    if(head==NULL){
        head = last = newnode;
    }else{
        last->next = newnode;
        last = newnode;
    }
    count++;
}

//deleteNote method deletes a target item in the list.
template <class T>
void LinkedList<T>::deleteNote(T& item){
    if(head == NULL)
        cerr<<"empty list";
    else{
        if(head->data == item){
            node<T>* p = head;
            head = head->next;
            delete p;
            count--;
            if(head==NULL) last = NULL;
        }else{
            node<T>* p = head;
            node<T>* q = p->next;
            while(q!=NULL && q->data != item){
                p = q;
                q = q->next;
            }
            if(q!=NULL){
                p->next = q->next;
                count--;
                if(last == q) last = p;
                delete q;
            }
        }
    }
}

//destroyList destroys the list and releases the list from memory.
template <class T>
void LinkedList<T>::destroylist(){
    node<T> *p;
    while(head != NULL){
        p = head;
        head = head->next;
        delete p;
    }
    last = NULL;
    count = 0;
}

//
template <class T>
ostream& operator<<(ostream& os, LinkedList<T>& list) {
    if (list.count>0){
        node<T> *p = list.head;
        while (p != list.last && &p != NULL) {
            os << p->data << " " << endl;
            p = p->next;
        }
        os << p->data << endl << endl;
        return os;
    }else{
        cout << "There is nothing in this current List. " << endl << endl;
    }
}

//added search method that searches for an item target and returns the item in the LinkedList.
template <class T>
T& LinkedList<T>::search(T& t){
    node<T> *p = head;
    while(p!= NULL){
        if(p->data==t){
            return p->data;
        }else{
            p = p->next;
        }
    }
}

//Default destructor uses desroyList to simply delete the list and releases itself from memory.
template <class T>
LinkedList<T>::~LinkedList(){
    destroylist();
}

#endif //AIRLINEDB_LINKEDLIST_H