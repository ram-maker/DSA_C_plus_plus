#include <iostream>
using namespace std;

class DbConnection{
    DbConnection(){};
    DbConnection(const DbConnection&)=delete;
    DbConnection& operator=(const DbConnection&)=delete;
    public:
    static DbConnection& getDbConnection(){
        static DbConnection db_connection;
        return db_connection;
    }
   
};

int main(){
    DbConnection &db_connection=DbConnection::getDbConnection();
}

