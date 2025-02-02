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

    auto first_element = some_list.begin();
    advance(first_element, 2); // Move iterator to the 3rd element (0-based index)
    cout << "Third list element: " << *first_element << endl;

    return 0;

}