#include <iostream>
void reverse_string(char *);
int main(){
    char *some_string="This";
    reverse_string(some_string);
    return 0;
}

void reverse_string(char *given_string){
    int string_length=1;
    char temp;
    while (*given_string!='\0'){
        given_string++;
        string_length++;
    }
    char *reverse_string=new char[string_length];
    std::cout<<"String Length:"<<string_length<<std::endl;
    int count=0;
    given_string--;
    for(int i=string_length-1;i>=0;i--){
        reverse_string[count]=*(given_string);
        given_string--;
        count++;
    }
    reverse_string[string_length]='\0';
    std::cout<<std::endl;
    std::cout<<"Reverse string:"<<reverse_string<<std::endl;
    
}