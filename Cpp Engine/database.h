#ifndef DATABASE
#define DATABASE
#include <string> 
#include <mysqlx/xdevapi.h>

class Database{
    private:
        mysqlx::Session* session;
    public:
        Database();
        ~Database();
        bool connect(std::string host,std::string user,std::string password,std::string dbname, int port);
        void disconnect();
};

#endif