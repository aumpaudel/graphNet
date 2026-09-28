#ifndef DATABASE
#define DATABASE
#include <string> 
#include <mysqlx/xdevapi.h>

class Database{
    private:
        mysqlx::Session* session;
    public:
        Database(string host,string user,string password,string dbname,int port);
        ~Database();
        mysqlx::Session* connect(std::string host,std::string user,std::string password,std::string dbname, int port);
        void fetchData();
        void ubdateData();
        void disconnect();
};

#endif