#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

void printMap(map<std::string,std::string> given_map){
    for(auto pair:given_map){
        cout<<pair.first<<":"<<pair.second<<endl;
    }
}

int main(){
    map<std::string,std::string> some_map;
    some_map["name"]="ram";
    some_map["address"]="Pokhara";
    some_map["phone"]="9861064";
    printMap(some_map);
    auto first_reference=some_map.begin();
    advance(first_reference,1);
    first_reference->second="Kathmandu";
    cout<<endl;
    printMap(some_map);
    cout<<endl;
    auto name_value=some_map["name"];
    cout<<"name value:"<<name_value<<endl;
    some_map["name"]="harry";
    cout<<endl;
    printMap(some_map);
}