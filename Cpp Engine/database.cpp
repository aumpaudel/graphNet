#include "database.h"
#include <iostream>
using namespace std;

Database::Database(string host,string user,string password,string dbname,int port) {
    session = connect(host,user,password,dbname,port);
}

Database::~Database() {
    disconnect();
}

mysqlx::Session* Database::connect(string host,string user,string password,string dbname,int port){
    mysqlx::Session* session = new mysqlx::Session(host, port, user, password);
    return session;
}
