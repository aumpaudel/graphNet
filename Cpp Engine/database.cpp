#include "database.h"
#include <iostream>
using namespace std;

Database::Database() {
    session = nullptr;
}

Database::~Database() {
    disconnect();
}