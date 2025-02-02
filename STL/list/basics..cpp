#include <iostream>
#include <list>
using namespace std;
void printList(list<int> given_list){
    for(int some_int:given_list){
        cout<<some_int<<" ";
    }
    cout<<endl;
}

int main(){
      list<int> some_list = {23, 34, 8, 9, 0};
    printList(some_list);
    some_list.sort();
    printList(some_list);
    return 0;

}