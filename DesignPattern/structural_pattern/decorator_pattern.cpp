/*
Decorator pattern:
The overall goal of decorator pattern is to prevent class explosion.
Notification can be considered as an example of reference
For instance, if you want to send the notification from differenct channel then, the general tendency would be creating notification interface and then making concrete 
notification classes with eeach representing channel:FacebookNotification, MessageNotiifcation, WhatsappNotification, What if you want to add 
Facebook+MessageNotificaiton; the sub classes are likely to increase; so decorator pattern helps to overcome this tendency;intially it wraps a concrete type with a decorator;
then another decorator wraps the prior one; More example from the code
Wraps object inside an object;
*/
#include <iostream>
#include <memory>
using namespace std;
class Notifier{
    public:
    virtual void sendNotification()=0;
};

class MessageNotifier:public Notifier{
    string message;
    public:
    MessageNotifier(){

    }
    MessageNotifier(string message){
        this->message=message;
    }
 
    void sendNotification(){
        cout<<"Sending Notification from Message Channel,message:"<<message<<endl;
    }
};

class NotifierDecorator:public Notifier{
    protected:
    shared_ptr<Notifier> notifier;
    string message;
};

class FacebookNotifierDecorator:public NotifierDecorator{
    public:
    FacebookNotifierDecorator(shared_ptr<Notifier> notifier,string message){
        this->notifier=notifier;
        this->message=message;
    }

    void sendNotification(){
        notifier->sendNotification();
        cout<<"Sending notification from Facebook Channel,message:"<<message<<endl;
    }

};

class EmailNotifierDecorator:public NotifierDecorator{
    public:
    EmailNotifierDecorator(shared_ptr<Notifier> notifier,string message){
        this->notifier=notifier;
        this->message=message;
    }

    void sendNotification(){
        notifier->sendNotification();
        cout<<"Sending notification from Email Channel,message:"<<message<<endl;
    }
};

int main(){
    string message="Your order has been placed";
    shared_ptr<Notifier> notifier_message=make_shared<MessageNotifier>(message);
    notifier_message=make_shared<FacebookNotifierDecorator>(notifier_message,message);
    notifier_message=make_shared<EmailNotifierDecorator>(notifier_message,message);
    notifier_message->sendNotification();
}

