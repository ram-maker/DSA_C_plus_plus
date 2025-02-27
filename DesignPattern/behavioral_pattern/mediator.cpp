/*
    The mediator pattern  decouples the tight communication between different objects. Rather object interact and communicates with each other from mediator interface.
    It consists of
    Mediator:
    It is the interface from which colleagues communicates
    Collegaue:
    It is the interface which is implemented by concrete colleagues
    Concrete Colleague:
    They are the object that communiate with each other
    Concrete Mediator
    It implements mediator

*/
#include <iostream>
#include <memory>
using namespace std;
/*Mediator*/
class ChatRoomMediator{
    public:
};

/*Concrete Mediator*/
class DMChatRoomMediator{
    public:
};

/*Colleague*/
class User{
    public:
    virtual void joinChatRoom()=0;
    virtual void leaveChatRoom()=0;
    virtual void sendMessage()=0;

};

/*Concrete Colleague*/
class User1:public User{
    shared_ptr<ChatRoomMediator> chat_room_mediator;
    public:

};

/*Concrete Colleague*/
class User2:public User{
    shared_ptr<ChatRoomMediator> chat_room_mediator;
    public:
    void joinChatroom(){

    }
    void leaveChatRoom(){

    }
    void sendMessage()

};

int main(){
    
    return 0;
}