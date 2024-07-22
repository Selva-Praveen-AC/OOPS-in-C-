#include<bits/stdc++.h>
using namespace std;

class FlightBook{
    public:
    struct Bookings{
        int Ticket=50;
        int FlightId;
        int ticket;
        int price = 5000;
        int passengerCost;
        int id=1;
    };
    
    vector<Bookings>booking;

    void Booking(){
        Bookings bookings;
        cout<<"Enter the Flight Id : ";
        cin>>bookings.FlightId;
        cout<<"Enter the No of Ticket : ";
        cin>>bookings.ticket;
        if(bookings.ticket > bookings.Ticket){
            cout<<"Insufficient Ticket\n";
        } else{
            bookings.price+=200*bookings.ticket;
            bookings.passengerCost = bookings.price * bookings.ticket;
            bookings.Ticket -= bookings.ticket;
        }
        booking.push_back(bookings);
    }

    void Print(){
        for(auto book : booking){
            cout<<"The Flight Id : "<<book.FlightId<<" No of Ticket : "<<book.ticket<<" Available Ticket : "<<book.Ticket<<" Total Cost : "<<book.price<<" Passsenger Cost : "<<book.passengerCost<<endl;
        }
    }

    void Cancellation(){
        int id;
        cout<<"Enter the Flight Id: ";
        cin>>id;
        auto it = find_if(booking.begin(), booking.end(), [&](const Bookings& b){ return b.FlightId == id; });
            if(id==it->FlightId){
                booking.erase(it);
                cout<<"Cancellation successfully completed\n";
                return;
            }
            else{
                cout<<"Id is not found\n";
            }
    }
    
};

int main(){
    FlightBook fb;

    int choice;
    while(true){
        cout<<"      Airline Reservation    \n";
        cout<<"------------------------------\n";
        cout<<"1. Booking \n";
        cout<<"2. Print Details\n";
        cout<<"3. Cancellation\n";
        cout<<"------------------------------\n";

        cout<<"Enter the choice : ";
        cin>>choice;
        switch (choice)
        {
        case 1:
            fb.Booking();
            break;
        
        case 2:
            fb.Print();
            break;
        
        case 3:
        fb.Cancellation();
        break;
        
        default:
            cout<<"Invalid choice";
            break;
        }
    }
}
