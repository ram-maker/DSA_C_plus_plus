#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> vecs){
 for (int integer:vecs){
        cout<<integer<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v;
    v.push_back(10);
    v.push_back(2);
    v.push_back(30);
    v.push_back(8);
    printVector(v);
    v.insert(v.begin()+1,20);
    printVector(v);
    v.erase(v.begin()+2);
    printVector(v);
   
}