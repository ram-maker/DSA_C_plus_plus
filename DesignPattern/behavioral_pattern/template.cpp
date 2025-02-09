/*
This method is primarily used to refrain subclasses, each having same implementaion method: greatly reducing code duplication.The method sharing same implementaion is 
localized in superclass, and other methods that require customize implementaion are overriden in subclasses
Overall, this method provide the skeleton of the classes. 
It consists of templateMethod that wraps the general behaviour for all of its subclasses
It contain hooks(that can be overriden by subclasses) and virtual function 
*/
#include <iostream>
#include <cstring>
#include <cctype>
#include <memory>
using namespace std;
class CharacterBuffer{
    char *buffer=NULL;
    int getWordLegth(char *word){
        return strlen(word);
    }

    void allocateBuffer(int buffer_size){
        buffer=new char[buffer_size+1];
    }

    char* getCopiedBuffer(char *word){
        strcpy(buffer,word);
        return buffer;
    }

    public:
    /*Template Method:*/
    void performCaseSwithing(char *word){
        int word_length=getWordLegth(word);
        allocateBuffer(word_length);
        char *copied_buffer=getCopiedBuffer(word);
        this->getFinalWord(buffer,word_length);
    }
    virtual void getFinalWord(char *word,int word_length)=0;
    virtual void display(){
        cout<<"The final word is:"<<buffer<<endl;
    }
    
};
class UpperCaseBuffer:public CharacterBuffer{
    public:
    void getFinalWord(char *word,int word_length){
        for (size_t i = 0; i<word_length; ++i) {
            word[i] = toupper(static_cast<unsigned char>(word[i]));
        }
    }
};

class LowerCaseBuffer:public CharacterBuffer{
    public:
    void getFinalWord(char *word,int word_length){
        for (size_t i = 0; i<word_length; ++i) {
            word[i] = tolower(static_cast<unsigned char>(word[i]));
        }
    }
};


int main(){
    shared_ptr<UpperCaseBuffer> upper_case_buffer=make_shared<UpperCaseBuffer>();
    upper_case_buffer->performCaseSwithing("this is nice");
    upper_case_buffer->display();

    shared_ptr<LowerCaseBuffer> lower_case_buffer=make_shared<LowerCaseBuffer>();
    lower_case_buffer->performCaseSwithing("ThIS IS NICE");
    lower_case_buffer->display();
    return 0;
}