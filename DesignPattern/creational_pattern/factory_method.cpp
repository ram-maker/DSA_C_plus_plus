#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Vehicle{
    public:
     virtual void delivery()=0;
};

class Car:public Vehicle{
    public:
        void delivery() override{
            cout<<"Delivery by car"<<endl;
        }
};

class Bus:public Vehicle{
 public:
        void delivery() override{
            cout<<"Delivery by bus"<<endl;
        }
};

class VehicleFactory{
    public:
        virtual Vehicle* createVehicle()=0;
};

class CarFactory:public VehicleFactory{
 public:
         Vehicle* createVehicle() override{
            return new Car();
        } 
};

class BusFactory:public VehicleFactory{
 public:
        Vehicle* createVehicle() override{
            return new Bus();
        } 
};
int main(){
    VehicleFactory *car_factory=new CarFactory();
    VehicleFactory *bus_factory=new BusFactory();
    Vehicle *car=car_factory->createVehicle();
    Vehicle *vehicle=bus_factory->createVehicle();
    car->delivery();
    vehicle->delivery();
    return 0;
}