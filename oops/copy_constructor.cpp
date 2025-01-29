/*This is a program illustrating shallow and deep copy*/
#include <iostream>
#include <cstring>
using namespace std;
class Copy{
    char *word;
    public:
    Copy(char *word){
        this->word=new char[strlen(word)+1];
        strcpy(this->word,word);
    }
    Copy(Copy &copy_string){
        word=new char[strlen(copy_string.word)+1];
        strcpy(word,copy_string.word);
    }
    void print(){
        cout<<"Word:"<<word<<endl;
    }
    void change_word(char *word){
        delete this->word;
        this->word=new char[strlen(word)+1];
        strcpy(this->word,word);
    }
};
int main(){
    Copy copy("Ram");
    Copy copy2=copy;
    copy.print();
    copy2.print();
    copy2.change_word("Harry");
    copy.print();
    copy2.print();
    return 0;
}