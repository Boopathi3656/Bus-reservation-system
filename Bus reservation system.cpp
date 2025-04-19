#include<iostream>
#include <vector>
#include <string>
using namespace std;
class Bus{
public:
    int busnumber;
    string source;
    string destination;
    int capacity;
    int seatsavailable;
};
class Reservation {
public:
    int bookingid;
    int busnumber;
    string passengername;
    int numberofSeats;
};
vector<Bus>buses;
vector<Reservation>reservation;
void addbus(){
    Bus bus;
    cout<<"enter bus number: ";
    cin>>bus.busnumber;
    cout<<"enter source: ";
    cin>>bus.source;
    cout<<"enter destination: ";
    cin>>bus.destination;
    cout<<"enter capacity: ";
    cin>>bus.capacity;
    bus.seatsavailable = bus.capacity;
    buses.push_back(bus);
    cout<<"BUS ADDED SUCCESSFULLY";
}
void displayavailablebuses(){
    if (buses.empty()) {
        cout << "No buses available." << endl;
    }
    else{
        for(auto bus:buses){
            cout<<bus.busnumber<<"|"<<bus.source<<"|"<<bus.destination<<"|"<<bus.capacity<<"|"<<bus.seatsavailable<<endl;
        }
    }
}
Bus* findbus(int busno) {
    for (auto &bus : buses) {
        if (bus.busnumber == busno) {
            return &bus;
        }
    }
    return nullptr;
}
void makereservation(){
     if (buses.empty()) {
        cout<<"No buses available to make a reservation"<<endl;
    }
    else{
        int busno;
        cout<<"enter bus number to reserve bus: ";
        cin>>busno;
        Bus* selectbus = findbus(busno);
            if (selectbus == nullptr) {
            cout<<"Bus with number "<<busno<<" not found"<<endl;
        }
        if (selectbus->seatsavailable <= 0) {
            cout<<"No seats available on Bus Number "<<busno<< endl;
        }
        Reservation newreservation;
        newreservation.busnumber=selectbus->busnumber;
        cout<<"enter pasenger name: ";
        cin>>newreservation.passengername;
        cout<<"enter number of seat to be reserved: ";
        cin>>newreservation.numberofSeats;
        if(newreservation.numberofSeats>selectbus->seatsavailable){
            cout<<"not enough seats available"<<"only"<<selectbus->seatsavailable<<"avilable"<<endl;
        }
        newreservation.bookingid=reservation.empty()?1:reservation.back().bookingid+1;
        reservation.push_back(newreservation);
        selectbus->seatsavailable-=newreservation.numberofSeats;
        cout<<"reservation successful.your booking id is: "<<newreservation.bookingid<<endl;
    }
}
void displayreservations(){
    if(reservation.empty()){
        cout<<"no reservation made"<<endl;
    }
    else{
        for(auto &reservation:reservation){
            cout<<reservation.bookingid<<"|"<<reservation.busnumber<<"|"<<reservation.passengername<<"|"<<reservation.numberofSeats<<endl;
        }
    }
}
void cancelreservation(){
    if (reservation.empty()) {
        cout << "No reservations to cancel" << endl;
    }
    else{
        int bookingid;
        cout<<"enter bookingid to cancel reservation: ";
        cin>>bookingid;
        for(auto a=reservation.begin();a!= reservation.end(); a++){
            if(a->bookingid==bookingid){
                Bus* bus=findbus(a->busnumber);
                if(bus!=nullptr){
                    bus->seatsavailable += a->numberofSeats;
                }
                reservation.erase(a);
                cout <<"Reservation with Booking ID "<< bookingid<<" cancelled successful"<<endl;
            }
        }
    }
}

int main(){
    int choice;

    do {
        cout << "\n--- Bus Reservation System ---" << endl;
        cout << "1- Add Bus" << endl;
        cout << "2- Display Available Buses" << endl;
        cout << "3- Make Reservation" << endl;
        cout << "4- Display Reservations" << endl;
        cout << "5- Cancel Reservation" << endl;
        cout << "0- Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addbus();
                break;
            case 2:
                displayavailablebuses();
                break;
            case 3:
                makereservation();
                break;
            case 4:
                displayreservations();
                break;
            case 5:
                cancelreservation();
                break;
            case 0:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);
    return 0;
}