#ifndef GRAPH
#define GRAPH

#include <set>
#include <map>
#include <string>

class Graph{
    private:
        std::map<int,std::set<int>> adjList;
        std::map<int,std::string> nameOfUser;
    public:
        bool exist(int userId);
        void addUser(int userId,std::string userName);
        void removeUser(int userId);
        void addFriend(int userId1, int userId2);
        void removeFriend(int userId1,int userId2);
        void printGraph();
};

#endif