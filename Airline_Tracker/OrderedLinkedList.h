//
// Created by super on 19-Oct-17.
//

#ifndef AIRLINE_TRACKER_ORDEREDLINKEDLIST_H
#define AIRLINE_TRACKER_ORDEREDLINKEDLIST_H


#include <iostream>
#include "LinkedList.h"

using namespace std;

template <class T>
class OrderedLinkedList: public LinkedList{
public:
    virtual void inserFirst(T&);
    virtual void inserLast(T&);
    void insert(T&);
    virtual T& search(T&);
    virtual void deleteNote(T&);
};

#endif //AIRLINE_TRACKER_ORDEREDLINKEDLIST_H
