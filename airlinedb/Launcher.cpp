// Name         : Launcher.h
// Author       : Kevin Tran
// Version      : 1.01
// Description  : Launcher.cpp class runs the console program and ensures that inputs from the user are valid.
// It runs as an instance and will perform the initial steps required for doing actions with the airline database such
// as adding a passenger, deleting a passenger, searching for a passenger, listing passengers per flight number, and
// quitting from the database program.

#include "OrderedLinkedList.h"
#include <sstream>
using namespace std;

//Passenger struct definition
struct Passenger{
    string first_name;
    string last_name;
    string address;
    string phoneNumber;

    //default constructor for Passenger
    Passenger(string last = "", string first = "", string address = "", string phoneNumber = ""){
        this->last_name=last;
        this->first_name=first;
        this->address=address;
        this->phoneNumber=phoneNumber;
    }

    //overloaded << to output Passenger correctly as "firstName lastName address phoneNumber".
    friend ostream& operator<<(ostream& os, Passenger p1){
        return os<<p1.first_name<<" "<<p1.last_name<<" ["<<p1.address<<"] ["<<p1.phoneNumber<<"]";
    }

    //overloaded == operator to compare two passengers if A is passenger B
    friend bool operator==(const Passenger& p1, Passenger& p2){
        return p1.last_name == p2.last_name && p1.first_name == p2.first_name;
    }

    //overloaded != operator to compare two passengers if A is not passenger B
    friend bool operator!=(const Passenger& p1, Passenger& p2){
        return p1.last_name != p2.last_name || p1.first_name == p2.first_name;
    }

    //overloaded < operator to compare two passengers if A is more (further in the alphabet) than passenger B
    friend bool operator>(Passenger& p1, Passenger& p2){
        if(p1.last_name==p2.last_name){
            return p1.first_name>p1.last_name;
        }else{
            return p1.last_name>p2.last_name;
        }
    }

    //overloaded < operator to compare two passengers if A is less (lesser in the alphabet) than passenger B
    friend bool operator<(Passenger& p1, Passenger& p2){
        if(p1.last_name==p2.last_name){
            return p1.first_name<p1.last_name;
        }else{
            return p1.last_name<p2.last_name;
        }
    }
};


//launcher class definition
//It is also an object in case multiple instances are ran at once.
class launcher{
    OrderedLinkedList<Passenger> *listLevels;
public:

    //Default constructor for a run instance.
    launcher(){
        this->listLevels = new OrderedLinkedList<Passenger>[4];
    };

    //checkLastName method checks user input so that the first name is purely a string.
    string checkLastName() {
        string last_name;

        //a double value to take in integers or doubles IF THE INPUT CAN BE CONVERTED TO A NUMERICAL VALUE
        double check;
        cout << "Enter last name: ";
        cin >> last_name;
        cout << endl;

        //stringstream is used to attempt to convert the input into a numerical value, if so then clear cin,
        //give an error message, and then recursively ask for a last name again.
        stringstream s(last_name);
        if (s >> check) {
            cin.ignore(INTMAX_MAX, '\n');
            cout <<  "Invalid Last Name Input. Try again. " << endl << endl;
            return checkLastName();
        } else {
            return last_name;
        }
    }

    //checkFirstName method checks user input so that the first name is purely a string.
    string checkFirstName() {
        string first_name;

        //a double value to take in integers or doubles IF THE INPUT CAN BE CONVERTED TO A NUMERICAL VALUE
        double check;
        cout << "Enter first name: ";
        cin >> first_name;
        cout << endl;

        //stringstream is used to attempt to convert the input into a numerical value, if so then clear cin,
        //give an error message, and then recursively ask for a first name again.
        stringstream s(first_name);
        if (s>>check) {
            cin.ignore(INTMAX_MAX, '\n');
            cout << "Invalid First Name Input. Try again. " << endl << endl;
            return checkFirstName();
        } else {
            return first_name;
        }
    }

    //checkFlightNumber method checks user input so that they do not enter a non-integer value, a negative integer,
    //and/or an integer that is not 100, 200, 300, or 400.
    int checkFlightNumber(){
        int flight_number;
        cout<<"Enter flight number: ";
        cin>>flight_number;
        cout<<endl;

        //while loop will start if constraints are not met. It will clear the cin and give a user error and recurses
        //the process to make sure it is entered correctly.
        while(cin.fail()==true || flight_number/100>4 || flight_number%100!=0 || flight_number/100<0){
            cin.clear();
            cin.ignore(INTMAX_MAX, '\n');
            cin.sync();
            cout<<"Invalid flight number input. Try again. "<< endl << endl;
            return checkFlightNumber();
        }
        return flight_number/100;
    }

    //add method starts the steps to add a Passenger to a specific flight number.
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

    //search method starts the steps to do searches a Passenger from the flight numbers.
    void search(){
        string last_name, first_name;
        int flight_number_index;
        last_name=checkLastName();
        first_name=checkFirstName();
        flight_number_index=checkFlightNumber();
        Passenger temp(last_name, first_name);
        Passenger person = listLevels[flight_number_index].search(temp);
        if(&person!=NULL){
            cout << person<<endl<<endl;
        }else {
            cout << "Could not find contact. " << endl << endl;
        }
    }

    //delete_Contact method starts the steps to delete the contact from a flight number.
    void delete_Contact(){
        string last_name, first_name;
        int flight_number_index;
        last_name=checkLastName();
        first_name=checkFirstName();
        flight_number_index=checkFlightNumber();
        Passenger temp(last_name, first_name);
        listLevels[flight_number_index].deleteNote(temp);
    }

    //list method will print the list of passengers on a specific flight number.
    void list(){
        int flight_number_index;
        flight_number_index=checkFlightNumber();
        cout<<listLevels[flight_number_index];
    }

    //run method will run the instance of the program and check user input for a valid char to perform operations.
    int run() {
        char check;
        while(check!='q' || check!='Q') {
            cout<<"Please	choose	an	operation:"<<endl;
            cout << "A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	|Q(Quit):	";
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
                        break;
                    case 's':
                    case 'S':
                        search();
                        break;
                    case 'd':
                    case 'D':
                        delete_Contact();
                        break;
                    case 'l':
                    case 'L':
                        list();
                        break;
                    case 'q':
                    case 'Q':
                        return 0;
                        break;
                    default:
                        cout << endl << "Invalid Command" << endl << endl;
                        break;
                }
            }
        }
        return 0;
    }
};

//main method will run instance until user quits.
int main(){
    cout<<"***DELTA AIRLINES***"<<endl;
    //creates the launcher object.
    launcher *inst = new launcher();
    //start running the program
    while(inst->run()!=0)
        return 0;
}