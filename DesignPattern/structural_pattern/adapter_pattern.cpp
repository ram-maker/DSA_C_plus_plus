/*
Adpater pattern is used when two incomaptible interface has to be integrated,
It doesnt modify the actual behaviour of the object rather just transform the incomaptible object to compatible one,
The adapter pattern generally consists of:
adaptee: 
This is generally a class that need to be adopted; Generally this class involve a legacy system , in which client has least control over.
They involve a third party system, a library 
It is a concrete type 

Target:
This is a interface that client expects, It defines method which makes adaptee compatible with client

AdapterClass:
This is the concrete implementation of Target

Client:
This is the client that leverage adapterclass to perform certain functionalities

*/
#include <iostream>
#include <memory>
using namespace std;

class CSVRendrer{
    string name="";
    string age="";
    public:
    CSVRendrer(){}
    CSVRendrer(string name, string age){
        this->name=name;
        this->age=age;
    }

    std::string getCSV(){
        return '"'+name+'"'+','+age;
    }

};

class Renderer{
    public:
    virtual void render()=0;
};

class RendererAdpater:public Renderer{
    CSVRendrer csv;
    string name="";
    string age="";
    public:
    RendererAdpater(){

    }

    RendererAdpater(CSVRendrer &csv_renderer){
        this->csv=csv_renderer;
    }

    void render(){
        string csv_string=csv.getCSV();
        int start=0;
        int end=csv_string.find(",");
        name=csv_string.substr(start,end);
        start=end+1;
        age=csv_string.substr(start);        
    }

    std::string getJson(){
         return "{\"" + name + "\":\"" + age + "\"}";
    }
};

int main(){
    CSVRendrer csv_render("Ram","24");
    RendererAdpater json_render(csv_render);
    json_render.render();
    string json_string=json_render.getJson();
    cout<<"Json String:"<<json_string<<endl;
    return 0;
}