/*
This pattern works on pub-sub mechanism, there will be single publisher and multiple subscribers
*/
#include <iostream>
#include <vector>
#include <memory>
using namespace std;
/*Observer*/
class Customer{
    public:
    virtual void update(string)=0;

};
/*Concrete Observer*/
class IphoneSubscriber:public Customer{
    public:
    void update(string subscriber_message){
        cout<<"Notified for IphoneSubscriber:subscription_message:"<<subscriber_message<<endl;
    }
};

/*Concrete Observer 1*/
class DesktopSubscriber:public Customer{
    public:
    void update(string subscriber_message){
        cout<<"Notified for DesktopSubscriber:subscription_message:"<<subscriber_message<<endl;
    }
};

/*Concrete Observer 2*/
class LaptopSubscriber:public Customer{
    public:
    void update(string subscriber_message){
       cout<<"Notified for LaptopSubscriber:subscription_message:"<<subscriber_message<<endl;
    }
};

/*Subject*/
class Store{
    vector<shared_ptr<Customer>> customers;
    void notifySubscriber(string subscriber_message){
        for (shared_ptr<Customer> customer:customers){
            customer->update(subscriber_message);
        }
    }
    public:
    void confirmProductEntry(string product){
        string subscriber_message="New product available, product:"+product;
        notifySubscriber(subscriber_message);
    }
    void addCustomer(shared_ptr<Customer> customer){
        customers.push_back(customer);
    }
  
};
 
int main(){
    Store s;
    shared_ptr<Customer> iphone_costumer=make_shared<IphoneSubscriber>();
    shared_ptr<Customer> desktop_costumer=make_shared<DesktopSubscriber>();
    shared_ptr<Customer> laptop_costumer=make_shared<LaptopSubscriber>();
    s.addCustomer(iphone_costumer);
    s.addCustomer(desktop_costumer);
    s.addCustomer(laptop_costumer);
    s.confirmProductEntry("Iphone 12");
} 