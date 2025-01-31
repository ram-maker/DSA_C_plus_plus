#include <iostream>
using namespace std;
class Num{
    int num;
    public:
    Num(int num){
        this->num=num;
    }
    void  operator ++(){
        this->num=num++;
    }
    void operator ++(int){
        this->num=++num;
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
    num++;
    num.display();

}