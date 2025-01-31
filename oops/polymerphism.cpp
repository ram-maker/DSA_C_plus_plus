#include <iostream>
using namespace std;

class Base{
    public:
        virtual void display(){
            cout<<"This is base class"<<endl;
        }
};

class Derive1:public Base{
    void display(){
        cout<<"This is derive1 class"<<endl;

    }
};
class Derive2:public Base{
    void display(){
        cout<<"This is derive 2 class"<<endl;
    }
};

void takesBaseObject(Base *base_obj){
    base_obj->display();
}

int main(){
    Base *base=new Derive1();
    takesBaseObject(base);
    // base->display();
    return 0;
}