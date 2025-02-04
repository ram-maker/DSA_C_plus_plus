#include <iostream>
#include <memory>
#include <bits/stdc++.h>
using namespace std;
class Document{
    public:
    virtual void renderPage()=0;
};
class Pdf:public Document{
    public:
    void renderPage(){
        cout<<"Rendering page for PDF"<<endl;
    }
};
class Excel:public Document{
    public:
    void renderPage(){
        cout<<"Rendering page for Excel"<<endl;
    }
};
class Word:public Document{
 public:
    void renderPage(){
        cout<<"Rendering page for Word"<<endl;
    }
};
class DocumentFactory{
    public:
    virtual shared_ptr<Document> createDocument()=0;

};
class PdfFactory:public DocumentFactory{
    public:
    shared_ptr<Document> createDocument(){
        return make_shared<Pdf>();
    }
};
class WordFactory:public DocumentFactory{
    public:
    shared_ptr<Document> createDocument(){
        return make_shared<Word>();

    }
};
int main(){
    shared_ptr<DocumentFactory> document_factory=make_shared<PdfFactory>();
    shared_ptr<Document> document=document_factory->createDocument();
    document->renderPage();
    shared_ptr<DocumentFactory> word_factory=make_shared<WordFactory>();
    shared_ptr<Document> word=word_factory->createDocument();
    word->renderPage();
    return 0;
}
