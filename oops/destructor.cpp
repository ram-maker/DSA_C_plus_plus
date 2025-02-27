/*Destructor called are in reverse order of constructor called*/
#include <iostream>
using namespace std;
class SecondBaseClass{
    public:
    SecondBaseClass(){
        cout<<"This is second base class"<<endl;
    }
    ~SecondBaseClass(){
        cout<<"Destroying second base class"<<endl;
    }
};

class BaseClass{
    public:
    BaseClass(){
        cout<<"This is base class"<<endl;
    }
    ~BaseClass(){
        cout<<"Destroying Baseclass"<<endl;
    }
};

class DeriveClass:public BaseClass,public SecondBaseClass{//the constructor of base classes is called from left to right
    public:
    DeriveClass():BaseClass(),SecondBaseClass(){
        cout<<"This is derived class"<<endl;
    }
    ~DeriveClass(){
        cout<<"Destroying derived class"<<endl;
    }
};

int main(){
    DeriveClass d;
}