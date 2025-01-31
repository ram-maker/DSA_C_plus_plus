#include <iostream>
using namespace std;
class Num{
    int num;
    public:
    Num(int num){
        this->num=num;
    }
    friend void operator +(Num &_num){
        _num.num=_num.num+1;
    }
    void display(){
        cout<<"Num:"<<num<<endl;
    }

};

int main(){
    Num num(10);
    +num;
    num.display();
}