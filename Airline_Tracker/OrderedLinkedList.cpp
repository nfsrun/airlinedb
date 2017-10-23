//
// Created by super on 19-Oct-17.
//

#include "OrderedLinkedList.h"

using namespace std;

template <class T>
void OrderedLinkedList<T>::inserFirst(T& item){
    insert(item);
}
template <class T>
void OrderedLinkedList<T>::inserLast(T& item){
    insert(item);
}
template <class T>
T& OrderedLinkedList<T>::search(T& target){
    node <T> *temp = head;
    while(temp!=NULL){
        if(target==temp->data){
            return temp->data;
        }
        temp = temp -> next;
    }
    cout<<"Item not found in OrderedLinkedList";
    return NULL;
}
template <class T>
void OrderedLinkedList<T>::insert(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    node<T> *traverse = head;
    node<T> *traverseb4;
    if(head==NULL){
        head=last=temp;
    }else{
        while(traverse!=NULL || item<traverse->data){
            traverseb4=traverse;
            traverse=traverse->next;
        }
        traverseb4->next=temp;
        temp->next = traverse;
    }
}
template <class T>
void OrderedLinkedList<T>::deleteNote(T& item){
    node<T> *temp = new node<T>;
    temp->data = item;
    node<T> *traverse = head;
    node<T> *traverseb4;
    while(traverse->data!=item && traverse->next!=NULL){
        traverseb4=traverse;
        traverse=traverse->next;
    }
    if(traverse==head && head->data==item && head){
        head=head->next;
        delete traverse;
    }else if(traverse!=NULL) {
        traverseb4->next = traverse ->next;
        delete traverse;
    }
}
