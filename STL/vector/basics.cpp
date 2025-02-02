#include <iostream>
#include <vector>
#include <algorithm>
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
    sort(v.begin(),v.end(),greater<int>());
    printVector(v);
    sort(v.begin(),v.end());
    printVector(v);
    sort(v.begin(),v.end(),greater_equal<int>());
    printVector(v);
   
}