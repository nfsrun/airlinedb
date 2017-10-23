//============================================================================
// Name        : Airline Database (airlinedb)
// Author      : Kevin Tran
// Version     : 1.00
// Copyright   : 2017
// Description :
/*
 *      This assignment contains code to initiate a manual airline database that is organized into four different
 *      flights and is organized/optimized to work with differenct passengers. Optimization comes from the overriding
 *      of LinkedList into OrderedLinkedList where certain operations occur sooner vs wait times of an unorganized
 *      LinkedList.
 *      !!INPUTS ARE CASE SENSITIVE!!
 */

//============================================================================

#include <iostream>
#include "OrderedLinkedList.h"

using namespace std;

struct Passenger{
    string first_name;
    string last_name;
    string address;
    string phoneNumber;
    Passenger(string last = "", string first = "", string address = "", string phoneNumber = ""){
        this->last_name=last;
        this->first_name=first;
        this->address=last;
        this->phoneNumber=phoneNumber;
    }
    friend ostream& operator<<(ostream& os, Passenger p1){
        return os<<p1.first_name<<" "<<p1.last_name<<" ["<<p1.address<<"] ["<<p1.phoneNumber<<"]";
    }
    friend bool operator==(const Passenger& p1, Passenger& p2){
        if (&p2==NULL){
            return false;
        }else {
            return p1.last_name.at(0) == p2.last_name.at(0);
        }
    }
    friend bool operator>(Passenger& p1, Passenger& p2){
        return p1.last_name.at(0)>p2.last_name.at(0);
    }
    friend bool operator<(Passenger& p1, Passenger& p2){
        return p1.last_name.at(0)<p2.last_name.at(0);
    }
};

class launcher{
    OrderedLinkedList<Passenger> *listLevels;
public:
    launcher(){
        listLevels = new OrderedLinkedList[4];
    };
    string checkLastName(){
        string last_name;
        cout<<"Enter last name: ";
        cin>>last_name;
        cout<<endl;
        if(cin.fail()){
            cout << endl << "Invalid Input. Try again. " << endl << endl;
            return checkLastName();
        }
        return last_name;
    }
    string checkFirstName(){
        string first_name;
        cout<<"Enter first name: ";
        cin>>first_name;
        cout<<endl;
        if(cin.fail()){
            cout << endl << "Invalid Input. Try again. " << endl << endl;
            return checkFirstName();
        }
        return first_name;
    }
    int checkFlightNumber(){
        int flight_number;
        cout<<"Enter flight number: ";
        cin>>flight_number;
        cout<<endl;
        if(cin.fail()==false && flight_number/100<=4 && flight_number%100==0 && flight_number/100>=0){
            return flight_number/100;
        }else{
            cout<<"Invalid flight number input. Try again. "<< endl << endl;
            return checkFlightNumber();
        }
    }
    void add(){
        string last_name, first_name, address, phone;
        int flight_number_index;
        flight_number_index=checkFlightNumber();
        last_name=checkLastName();
        first_name=checkFirstName();
        cout<<"Enter address: ";
        cin>>address;
        cout<<endl<<"Enter phone: ";
        cin>>phone;
        cout<<endl;
        Passenger temp(last_name, first_name, address, phone);
        listLevels[flight_number_index].insert(temp);
    }
    void search(){
        string last_name, first_name;
        int flight_number_index;
        last_name=checkLastName();
        first_name=checkFirstName();
        flight_number_index=checkFlightNumber();
        Passenger temp(last_name, first_name);
        Passenger person = listLevels[flight_number_index].search(temp);
        if(person==NULL){
            cout << person;
        }else {
            cout << "Could not find contact. " << endl << endl;
        }
    }
    void delete_Contact(){
        string last_name, first_name;
        int flight_number_index;
        last_name=checkLastName();
        first_name=checkFirstName();
        flight_number_index=checkFlightNumber();
        Passenger temp(last_name, first_name);
        listLevels[flight_number_index].deleteNote(temp);
    }
    void list(){
        int flight_number_index;
        flight_number_index=checkFlightNumber();
        cout<<listLevels[flight_number_index];
    }
    int run() {
        cout << "A(Add)	|	P	(Append)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	";
        char check;
        cin >> check;
        cout << endl;
        if (cin.fail()) {
            cout << endl << "Invalid Command. Try again. " << endl << endl;
            run();
        } else {
            switch (check) {
                case 'a':
                case 'A':
                    add();
                    run();
                case 's':
                case 'S':
                    search();
                    run();
                case 'd':
                case 'D':
                    delete_Contact();
                    run();
                case 'l':
                case 'L':
                    list();
                    run();
                case 'q':
                case 'Q':
                    return 0;
                default:
                    cout << endl << "Invalid Command" << endl << endl;
                    run();
            }
        }
    }
};

int main(){
    cout<<"***DELTA AIRLINES***"<<endl;
    //creates the launcher object.
    launcher *inst = new launcher();
    //prepare and populate the phone book.
    cout<<"Please	choose	an	operation:"<<endl;
    //start running the program
    while(inst->run()==1)
        return 0;
}
