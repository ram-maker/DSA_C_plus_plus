#include <iostream>
using namespace std;
class Array{
    int size;
    int *arr_ptr;
    public:
    Array(){

    }
    Array(int *arr_ptr){
        this->arr_ptr=arr_ptr;
    }
    int operator[](int index){
        return *(arr_ptr+index);
    }
};

int main(){
    int some_array[]={9,0,8,7};
    Array arr(some_array);
    for(int i=0;i<4;i++){
        cout<<arr[i]<<",";
    }
    cout<<endl;
}