#include <iostream>
#include <bits/stdc++.h>
#include <memory>
using namespace std;
class Transportation{
    public:
    virtual void delivery()=0;

};
class PetrolBus:public Transportation{
    public:
    void delivery(){
        cout<<"Delivery by Petrol Bus"<<endl;
    }
};
class ElectricBus:public Transportation{
    public:
    void delivery(){
        cout<<"Delivery by Electric Bus"<<endl;
    }


};
class PetrolCar:public Transportation{
    public:
    void delivery(){
        cout<<"Delivery by Petrol Car"<<endl;
    }


};
class ElectricScooty:public Transportation{
    public:
    void delivery(){
        cout<<"Delivery by Electric Scooty"<<endl;
    }

    
};

class TransportationFactory{
    public:
    virtual shared_ptr<Transportation>  createPublicTransportation()=0;
    virtual shared_ptr<Transportation>  createPrivateTransportaion()=0;
};

class ElectricTransportFactory:public TransportationFactory{
    public:
    shared_ptr<Transportation> craetePublicTransportation(){
        return make_shared<ElectricBus>();

    }
    shared_ptr<Transportation> createPrivateTransportation(){
        return make_shared<ElectricScooty>();

    }
};
class PetrolTransportFactory:public TransportationFactory{
    public:
    shared_ptr<Transportation> craetePublicTransportation(){
        return make_shared<PetrolBus>();
    }
    shared_ptr<Transportation> createPrivateTransportation(){
        return make_shared<PetrolCar>();
        
    }
};
int main(){
    shared_ptr<TransportationFactory> electric_transportation_factory=make_shared<ElectricTransportFactory>();
    shared_ptr<Transportation> ev_scooty=electric_transportation_factory->createPrivateTransportaion();
    shared_ptr<Transportation> ev_bus=electric_transportation_factory->createPrivateTransportaion();
    
    shared_ptr<TransportationFactory> petrol_transportation_factory=make_shared<PetrolTransportFactory>();
    shared_ptr<Transportation> petrol_bus=petrol_transportation_factory->createPublicTransportation();
    shared_ptr<Transportation> petrol_car=petrol_transportation_factory->createPrivateTransportaion();

    ev_scooty->delivery();
    ev_bus->delivery();
    petrol_bus->delivery();
    petrol_car->delivery();


}