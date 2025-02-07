/*
Bridge pattern aims to decouple the abstraction from its implementation so that the two can vary independently. Sound's absurd?.Absolutely Generally the 
abstraction are directly coupled with their interface. Like if you have an animal interface, then dig is its subclass tightly related to animal. 

Bridge pattern let you split two like classes, which can be expanded independently. Imagine you need a class that have composite . Bridge pattern acts as if 
the bridge between two classes that are conceptually linked, but still both are independent interms of implementation. 

Example:
Imagine you are writing a software modules for an electronic devices that can be controlled by different communication protocol. For instance TV can be controlled 
from your remote and phone-uses RF communication and WiFI behind the hood.Since both devices can be controlled via remote(RF) and WiFI communication, there exists fo
llowing combination.
device={Fridge, TV} protocol={Remote, WiFi}.
RemoteFridge, RemoteTV, WiFiFridge, WiFiTV
All this devices  shares some certain feature, for instance their prices.
class Devices{
    public:
    virtual void getPrice()=0;
}
class RemoteFirdge:Devices{
    public:
    void getPrice(){
    //business logic for get price
    }
}
class RemoteTv:Devices{
    public:
    void getPrice(){
    //business logic for get price
    }
}
class WiFiFridge:Devices{
    public:
    void getPrice(){
    //business logic for get price
    }
}
class WiFiTV:Devices{
    public:
    void getPrice(){
    //business logic for get price
    }
}
So far so good, Now the problem errupts. I want to add one more devices in the list, like toyCar, which can be controlled both by remote and WiFI. Now the 
two momre additinal classes will be added, RemoteCar and WiFI car, having total 6 classes. still so far so good, now these devices can be controlled from
bluetooth as well, so whats the drill? Nothing, now we do have folowing combiantions in total:
device={Fridge, TV,ToyCar} protocol={Remote, WiFi,Bluetooth}.
{RemoteFridge, RemoteTV,RemoteToyCar,WiFiFridge, WiFiTV,WiFiToyCar,BluetoothFridge, BluetoothTV,BluetoothToyCar}=9 different combinations.Genrally 
the combination= no_of_devices*no_of_protocol

The problem this approach invite is:
The combinaions of classes increases exponentially.
What if the RemoteFridge has some methods that is not reqiured for RemoteTV. Violation of Interface segregation priciple:classes shouldnt be forces to use the 
method that they dont require it.

The bridge pattern helps to eradicate this by loosely decoupling the abstraction from its implementaion. It has:
Abstraction:
This is the high level interface that holds reference of an implementor

RefinedAbstraction:
It inherits abstraction, more like concrete absratcion

Implementor:
It defines the mechanism for concrete implementor, sholdnt depend tightly on abstraction

ConcreteImplementor:
Provides concrete implementaion of implementor
*/

#include <iostream>
#include <memory>
using namespace std;
/*Implementor*/
class Device{
    public:
    virtual string getDeviceName()=0;
};

/*Concrete Implementor*/
class ToyCar:public Device{
    public:
    string getDeviceName(){
        return "ToyCar";
    }
};
/*Abstraction*/
class Protocol{
    public:
    virtual string getFullDeviceName()=0;
};
/*Refined Abstraction*/
class BLE:public Protocol{
    shared_ptr<Device> device ;
    public:
    BLE(shared_ptr<Device> device){
        this->device=device;
    }
    string getFullDeviceName(){
        string device_name=device->getDeviceName();
        return "Bluetooth Low Energy "+device_name;
    }
};
int main(){
    shared_ptr<Device> toy_car=make_shared<ToyCar>();
    shared_ptr<Protocol>ble=make_shared<BLE>(toy_car);
    string device_name=ble->getFullDeviceName();
    cout<<"Deive name:"<<device_name<<endl;
    return 0;
}