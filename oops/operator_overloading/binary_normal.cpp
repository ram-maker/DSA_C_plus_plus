#include <iostream>
using namespace std;
class Complex{
    float imag;
    float real;
    public:
    Complex(){

    }
    Complex(float real, float imag){
        this->imag=imag;
        this->real=real;
    }

    Complex  operator +(Complex complex_number){
        Complex add;
        add.real=this->real+complex_number.real;
        add.imag=this->imag+complex_number.imag;
        return add;
    }

    Complex operator -(Complex complex_number){
        Complex sub;
        sub.real=this->real-complex_number.real;
        sub.imag=this->imag-complex_number.imag;
        return sub;
    }
    
    void display(){
        cout<<"Num:"<<real<<" +i"<<imag<<endl;
    }

};
int main(){
  Complex complex1(3.8,6.2);
  Complex complex2(0.2,2.8);
  Complex add=complex1+complex2;
  Complex sub=complex1-complex2;
  add.display();
  sub.display();
}