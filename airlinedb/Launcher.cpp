// Name         : Launcher.h
// Author       : Kevin Tran
// Version      : 1.03 -- Fixed adding and removing issues.
// Description  : Launcher.cpp class runs the console program and ensures that
// inputs from the user are valid. It runs as an instance and will perform the
// initial steps required for doing actions with the airline database such as
// adding a passenger, deleting a passenger, searching for a passenger, listing
// passengers per flight number, and quitting from the database program.

#include "Validator.h"
#include "OrderedLinkedList.h"
#include "Passenger.h"

using namespace std;

//launcher class definition
//It is also an object in case multiple instances are ran at once.
class launcher{
        OrderedLinkedList<Passenger> *listLevels;
public:

    //Default constructor for a run instance.
    launcher(){
        this->listLevels = new OrderedLinkedList<Passenger>[4];
    };


    //add method starts the steps to add a Passenger to a specific flight
    //number.
    void add(){
        string last_name, first_name, address, phone;
        int flight_number_index;
        flight_number_index=checkFlightNumber();
        last_name=checkLastName();
        first_name=checkFirstName();

        //address will be entered through getLine so that it can cover spaced
        //inputs
        cout<<"Enter address: ";
        cin.ignore(INTMAX_MAX, '\n');
        getline(cin, address);

        //phone
        cout<<endl<<"Enter phone: ";
        cin>>phone;
        cout<<endl;
        Passenger temp(last_name, first_name, address, phone);
        listLevels[flight_number_index].insert(temp);
    }

    //search method starts the steps to do searches a Passenger from the flight
    //numbers.
    void search(){
        string last_name, first_name;
        int flight_number_index;
        last_name=checkLastName();
        first_name=checkFirstName();
        flight_number_index=checkFlightNumber();
        Passenger temp(last_name, first_name, "", "");
        Passenger person = (listLevels[flight_number_index].search(temp));
        Passenger test = Passenger();
        if(person!=test){
            cout << person<<endl<<endl;
        }else{
            cout << "Could not find contact. " << endl << endl;
        }
    }

    //delete_Contact method starts the steps to delete the contact from a flight
    //number.
    void delete_Contact(){
        string last_name, first_name;
        int flight_number_index;
        last_name=checkLastName();
        first_name=checkFirstName();
        flight_number_index=checkFlightNumber();
        Passenger temp(last_name, first_name, "", "");
        listLevels[flight_number_index].deleteNote(temp);
    }

    //list method will print the list of passengers on a specific flight number.
    void list(){
        int flight_number_index;
        flight_number_index=checkFlightNumber();
        cout<<listLevels[flight_number_index];
    }

    //run method will run the instance of the program and check user input for a
    //valid char to perform operations.
    int run() {
        char check;
        while(check!='q' || check!='Q') {
            cout<<"Please	choose	an	operation:"<<endl;
            cout << "A(Add)	|	S	(Search)	|	D(Delete)	|L(List)	" <<
                    "|Q(Quit):	";
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