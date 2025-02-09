/*
It is a pattern that add one level of indirection for client to access real object:
Generally three exists of proxy:
remote:
generally implemented for acceisng the remote resource, such as database

virtual:
sometimes object construction is expensive, depsite constructing object if some method is not invoked; the whole idea of object creation is not invoked at all.
Thus thus helps for lazy intialization. It helps to delay the object creation untill it actually needded

protection:
add certain level of authorization before invoking a funciton

Proxy helps to delay the instaniation of object creation;object is created only when method is invoked else, the expensive object is not created.
The client interacts only with the proxy rather than realConcreteObject,

Use cases:
Authorization
Lazy laoding
Caching
*/
#include <iostream>
#include <memory>
using namespace std;
/*Expensive*/
class BookParser{
    public:
    virtual int getBookLength()=0;
    virtual int getBookSize()=0;
};
class ComicBookParser:public BookParser{
    string book_content;
    public:
    ComicBookParser(string book_content){
        this->book_content=book_content;
    }
    int getBookLength(){
        return book_content.length();
    }
    int getBookSize(){
        return book_content.size();
    }
};
class BookParserProxy:public BookParser{
    shared_ptr<ComicBookParser> book_parser;
    string book_content;
    void createObjectIfNotExists(){
        if (!book_parser){
            book_parser=make_shared<ComicBookParser>();
        }
    }
    public:
    BookParserProxy(string book_content){
        this->book_content=book_content;
    }
    int getBookLength(){
        createObjectIfNotExists();
        return book_parser->getBookLength();
    }
    int getBookSize(){
        createObjectIfNotExists();
        return book_parser->getBookSize();
    }
};
int main(){
    shared_ptr<BookParser> book_parser_proxy=make_shared<BookParserProxy>("this is the best we can do as a human, good luck with it");
    int book_length=book_parser_proxy->getBookLength();
    cout<<"Book Length:"<<book_length<<endl;
}
