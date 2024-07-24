#include<bits/stdc++.h>
using namespace std;

class Taxi{
    public:
    int id;
    bool isFree;
    char pickup_point;
    char drop_point;
    int pickup_time;
    int drop_time;
    int current_point = 'A';
    double amount;
    double total_amount;

    Taxi(int id){
        this->id = id;
        this->isFree=true;
        this->pickup_point=pickup_point;
        this->drop_point=drop_point;
        this->pickup_time=pickup_time;
        this->drop_time=drop_time;
        this->current_point=current_point;
        this->amount=amount;
        this->total_amount=total_amount;
    }
};

class TaxiBooking{
    public:
        vector<Taxi>taxi;

    TaxiBooking(){
        for(int i=0;i<4;i++){
            taxi.push_back(Taxi(i+1));
        }
    }

    void BookTaxi(){
        for(int i=0;i<4;i++){
            if(taxi[i].isFree){
                cout<<"Customer ID : "<<taxi[i].id<<endl;
                taxi[i].id=i+1;
                cout<<"Enter the Pickup Point : ";
                cin>>taxi[i].pickup_point;
                cout<<"Enter the Drop point : ";
                cin>>taxi[i].drop_point;
                cout<<"Enter the Pickup Time : ";
                cin>>taxi[i].pickup_time;
                taxi[i].drop_time = taxi[i].pickup_time +abs(taxi[i].pickup_point - taxi[i].drop_point);
                taxi[i].amount=(double)100+((15*abs(taxi[i].pickup_point-taxi[i].drop_point))-5)*10;
		        taxi[i].total_amount+=(double)100+((15*abs(taxi[i].pickup_point-taxi[i].drop_point))-5)*10;
                taxi[i].isFree=false;
                cout<<"Taxi Id : "<<taxi[i].id<<"\nIs Booked now"<<endl; 
            }
            else if(taxi[i].id&&!taxi[i].isFree){
                cout<<"Taxi is already booked\n";
            }
        }
        
    }

    void Print_Taxi(){
        for(auto t:taxi){
            if(!t.isFree){
                cout<<"Taxi Id : "<<t.id<<" Pickup point : "<<t.pickup_point<<" Drop point : "<<t.drop_point<<" Pickup Time : "<<t.pickup_time<<" Drop Time : "<<t.drop_time<<" Total amount : "<<t.total_amount<<endl;
            }
        }
    }

    void Taxi_status(){
        for(auto t:taxi){
            cout<<"Status of Taxi No : "<<t.id<<" '"<<(t.isFree?"Available":"Booked")<<"'"<<endl;
        }
        cout<<endl;
    }

    void Cancelation(){
        int bid;
        cout<<"Enter the ID of the Customer : ";
        cin>>bid;
        for(int i=0;i<4;i++){
            if(bid==taxi[i].id&&!taxi[i].isFree){
                taxi[i].isFree=true;
                cout<<"Successfully Taxi Booking is Cancelled"<<endl;
                return;
            }
            else{
                cout<<"Taxi is not found"<<endl;
            }
        }
    }
};

int main(){
    TaxiBooking tb;
    int choice;
    while(true){
        cout<<"Enter the choice : ";
        cin>>choice;

        switch (choice)
        {
        case 1:
            tb.BookTaxi();
            break;
        
        case 2:
            tb.Print_Taxi();
            break;

        case 3:
            tb.Taxi_status();
            break;
        
        case 4:
            tb.Cancelation();
            break;

        default:
            cout<<"Enter valid choice";
            break;
        }
    }
}
