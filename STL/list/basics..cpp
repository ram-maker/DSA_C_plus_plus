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
    list<int> lista = {23, 34, 8, 9, 0};
    printList(lista);
    lista.sort();
    printList(lista);
    auto listb={3,90,12,67};
    lista.sort(greater<int>());
    printList(lista);
    lista.reverse();
    printList(lista);
    lista.merge(listb);
    printList(lista);
    auto size=lista.size();
    return 0;

}