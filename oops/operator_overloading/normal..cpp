#include <iostream>
using namespace std;
class Num{
    int num;
    public:
    Num(int num){
        this->num=num;
    }
    Num &operator +(){
        num=++num;
        return *this;
    }
    void changeNum(int num){
        this->num=num;
    }
    void display(){
        cout<<"Num:"<<num<<endl;
    }

};
int main(){
    Num num(10);
    Num &num_one=+num;
    num.changeNum(20);
    num_one.display();
    num.display();
}