/*
The primary purpose of the Null Object Pattern is to avoid null checks when dealing with object pointers that might be set to nullptr
*/
#include <iostream>
#include <memory>
using namespace std;
class Logger{
    public:
    virtual void  log(string log_message)=0;
};

class FileLogger:public Logger{
    public:
    void log(string log_message){
        cout<<"File:"<<log_message<<endl;
    }  
};

class ConsoleLogger:public Logger{
    public:
    void log(string log_message){
        cout<<"Console:"<<log_message<<endl;
    }
};

class NullLogger:public Logger{
    public:
    void log(string log_message){
        //does nothing
    }
};

int main(){
    shared_ptr<Logger> file_logger=make_shared<FileLogger>();
    shared_ptr<Logger> console_logger=make_shared<ConsoleLogger>();
    file_logger->log("Temp.txt doesnt exists");
    console_logger->log("Stdeerr");
    shared_ptr<Logger> null_logger=make_shared<NullLogger>();
    null_logger->log("This is null logger");

}