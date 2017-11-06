// Name         : Passenger.h
// Author       : Kevin Tran
// Description  : Passenger.h class separates the Passenger into it's own class
// and contains methods and fields that define what a Passenger object is. It
// includes various operator overloading methods so that it can work when
// Passengers are being compared to each other or when they have to be outputted
// because of an output function from it's OrderedLinkedList.

#ifndef AIRLINEDB_PASSENGER_H
#define AIRLINEDB_PASSENGER_H

#include <string>
using namespace std;

//Passenger struct definition
class Passenger{
    string first_name;
    string last_name;
    string address;
    string phoneNumber;
public:
    Passenger(string = "", string = "", string = "", string = "");
    friend ostream& operator<<(ostream&, Passenger);
    friend bool operator==(const Passenger&, Passenger&);
    friend bool operator!=(const Passenger&, Passenger&);
    friend bool operator>(const Passenger&, Passenger&);
    friend bool operator<(const Passenger&, Passenger&);
};

//default constructor for Passenger
Passenger::Passenger(string last, string first, string address, string
phoneNumber){
    this->last_name=last;
    this->first_name=first;
    this->address=address;
    this->phoneNumber=phoneNumber;
}

//overloaded << to output Passenger correctly as "firstName lastName address
//phoneNumber".
ostream& operator<<(ostream& os, Passenger p1){
    return os<<p1.first_name<<" "<<p1.last_name<<" ["<<p1.address<<"] ["
             <<p1.phoneNumber<<"]";
}

//overloaded == operator to compare two passengers if A is passenger B
bool operator==(const Passenger& p1, Passenger& p2){
    return p1.last_name == p2.last_name && p1.first_name == p2.first_name;
}

//overloaded != operator to compare two passengers if A is not passenger B
bool operator!=(const Passenger& p1, Passenger& p2){
    return p1.last_name != p2.last_name || p1.first_name != p2.first_name;
}

//overloaded < operator to compare two passengers if A is more (further in the
//alphabet) than passenger B
bool operator>(const Passenger& p1, Passenger& p2){
    if(p1.last_name==p2.last_name){
        return p1.first_name>p1.first_name;
    }else{
        return p1.last_name>p2.last_name;
    }
}

//overloaded < operator to compare two passengers if A is less (lesser in the
//alphabet) than passenger B
bool operator<(const Passenger& p1, Passenger& p2){
    if(p1.last_name==p2.last_name){
        return p1.first_name<p1.first_name;
    }else{
        return p1.last_name<p2.last_name;
    }
}

#endif //AIRLINEDB_PASSENGER_H
