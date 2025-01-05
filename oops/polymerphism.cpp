#include <iostream>
using namespace std;
class Base{
    public:
        virtual void display(){
            cout<<"This is base class"<<endl;
        }
};

class Derive:public Base{
    void display(){
        cout<<"This is derive class"<<endl;

    }
};
int main(){
    Base *base=new Derive();
    base->display();
    return 0;
}