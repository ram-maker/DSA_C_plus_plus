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
    String operator+(String string_obj){
        String s;
        s.size=this->size+string_obj.size;
        s.string=new char[s.size+1];
        strcat(this->string,string_obj.string);
        strcpy(s.string,this->string);
        return s;
    }
    void display(){
        std::cout<<"string:"<<string<<",len:"<<size<<std::endl;
    }
      
};
int main(){
    String s1("Ram ");
    String s2("is a good boy");
    String concate_string=s1+s2;
    concate_string.display();
}