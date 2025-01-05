#include <iostream>
using namespace std;
class Shape{
    public:
        void displayShapeName(std::string shape_name){
            cout<<"This shape is: "<<shape_name<<endl;
        }
};
int main(){
    Shape *rectangle=new Shape();
    rectangle->displayShapeName("rectangle");
    return 0;
}