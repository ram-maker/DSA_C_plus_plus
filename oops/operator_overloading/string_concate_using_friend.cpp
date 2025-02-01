#include <iostream>
#include <cstring>
class String{
    char *string;
    int size;
    public:
    String(){

    }
    String(char *string){
        size=strlen(string);
        this->string=new char[size+1];
        strcpy(this->string,string);
    }
    friend String operator+(String string_obj1,String string_obj2){
        String s;
        s.size=string_obj1.size+string_obj2.size;
        s.string=new char[s.size+1];
        strcat(string_obj1.string,string_obj2.string);
        strcpy(s.string,string_obj1.string);
        return s;
    }
    void display(){
        std::cout<<"string:"<<string<<",len:"<<size<<std::endl;
    }
      
};

int main(){
    String s1("Hari ");
    String s2("is a good boy");
    String concate_string=s1+s2;
    concate_string.display();
}