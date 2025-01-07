#include <iostream>
#include <memory>
#include <bits/stdc++.h>
using namespace std;
class Vehicle{
    public:
    virtual void delivery()=0;
};
class Bus:public Vehicle{
    public:
    void delivery(){
        cout<<"Delivery by Bus"<<endl;
    }
};
class Tempo:public Vehicle{
    public:
    void delivery(){
        cout<<"Delivery by Tempo"<<endl;
    }

};
class VehicleFactory{
    public:
        virtual shared_ptr<Vehicle> createVehicle()=0;
};
class BusFactory:public VehicleFactory{
    public:
    shared_ptr<Vehicle> createVehicle(){
        return make_shared<Bus>();
    }
};
class TempoFactory:public VehicleFactory{
   public:
    shared_ptr<Vehicle> createVehicle(){
        return make_shared<Tempo>();
    }
};
int main(){
    shared_ptr<VehicleFactory> bus_factory=make_shared<BusFactory>();
    shared_ptr<VehicleFactory> tempo_factory=make_shared<TempoFactory>();
    shared_ptr<Vehicle>  bus=bus_factory->createVehicle();
    shared_ptr<Vehicle>  tempo=tempo_factory->createVehicle();
    bus->delivery();
    tempo->delivery();
    return 0;
}
