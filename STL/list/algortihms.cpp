#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
 using namespace std;

 void findNumber(vector<int> some_vector,int number){
    auto it=find(some_vector.begin(),some_vector.end(),number);
    if (it!=some_vector.end()){
        int index=distance(some_vector.begin(),it);
        cout<<"It:"<<*it<<endl;
    }else{
        cout<<"Number Doesnt exits"<<endl;
    }
 }

void adjacentFind(vector<int> some_vector){
    auto it=adjacent_find(some_vector.begin(),some_vector.end());
      if (it!=some_vector.end()){
        cout<<"Ajacent number:"<<*it<<endl;
    }else{
        cout<<"Adjacent number doesnt exits"<<endl;
    }
 }

 
 int main(){
    vector<int> some_vector={12,12,2,3,4};
    auto count_value=count(some_vector.begin(),some_vector.end(),1);
    cout<<"count value:"<<count_value<<endl;  
    
 }