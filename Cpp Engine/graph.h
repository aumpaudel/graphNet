#ifndef GRAPH
#define GRAPH

#include <set>
#include <map>
#include <string>
#include <vector>
#include <utility>

class Graph{
    private:
        std::map<int,std::set<int>> adjList;
        std::map<int,std::string> nameOfUser;
    public:
        //graph
        std::map<int,std::string> getAllUsers() const;
        std::vector<std::pair<int,int>> getAllFriendships() const;
        bool exist(int userId);
        bool addUser(int userId,std::string userName);
        bool removeUser(int userId);
        bool addFriend(int userId1, int userId2);
        bool removeFriend(int userId1,int userId2);
        void printGraph();
        //bfs
        std::vector<int> bfs(int start);
        //dfs
        std::vector<int> dfs(int start);
        //shortest path
        std::pair<std::vector<int>,int> shortestPath(int start, int end);
        //recommendation
        std::vector<int> mutualFriends(int user1,int user2);
        std::vector<int> recommendFriends(int userId);
        //connected
        std::vector<std::vector<int>> connectedComponents();
        int componentCount();
        //statistics
        int totalUsers();
        int totalConnections();
        double averageFriends();
        int mostConnectedUser();
};

#endif