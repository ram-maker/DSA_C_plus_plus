/*
Especially suited for the collections, having treee structure.
Despite having leaf and collection of differnt types, it treats both as same,
If not composite pattern then, we had to deal with lot of conditinal if statement
Overall the pattern can be disected into:
1.Component:
A common interface that composte and leaves concretize.

2.Composite
It has children which may be of composite type and leaves as well. It can be extended.

3.Leaves:
It can be extended to children

In the sense of composite, it make sense to add nodes; which is nothing but adding a children, but  leaves cant have add metods, as it cant be extended
And other limitation that we have is since leaves and composite shares same interface, levaes cant be refrained from implementing a methods that is not required for it;thus potentially
violating the I principle, in some case L as well, 
*/
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
using namespace std;

/*Interface*/
class FileManger{
    public:
    virtual void add(shared_ptr<FileManger>)=0;
    virtual void remove(shared_ptr<FileManger>)=0;
    virtual void display()=0;
};

/*Composite*/
class Directory:public FileManger{
    vector<shared_ptr<FileManger>> file_manager_entities;
    string directory_name="";
    string file_name="";
    public:
    Directory(string directory_name,string file_name){
        this->directory_name=directory_name;
        this->file_name=file_name;
    }
    void add(shared_ptr<FileManger> file_manager){
        file_manager_entities.push_back(file_manager);
    }

    void remove(shared_ptr<FileManger> file_manager){
        cout<<"Removing now"<<endl;
    }

    void display(){
        // for (shared_ptr<FileManger> directories:file_manager_entities){
        //     cout<<"Dir"
        // }
        cout<<"File:"<<file_name<<",Directory:"<<directory_name<<endl;
    }

};

/*Leaf*/
class File:public FileManger{
    public:
    void add(shared_ptr<FileManger> file_manager){
        throw std::runtime_error("No method for add in leafes");
    }
    
    void remove(shared_ptr<FileManger> file_manager){
        throw std::runtime_error("No method for remove in leafes");
    }
    void display(shared_ptr<FileManger> file_manager){
        cout<<"This is file display method"<<endl;
    }
};

int main(){
    shared_ptr<FileManger> directory =make_shared<Directory>("root","tmp.txt");
    directory->display();
    return 0;
}