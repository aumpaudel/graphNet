#include <iostream>
#include "graph.h"
using namespace std;

map<int,string> Graph::getAllUsers() const{
    return nameOfUser;
}

vector<pair<int,int>> Graph::getAllFriendships() const{
    vector<pair<int,int>> ans;
    for(const auto& it:adjList) for(int i:it.second) if(it.first<i) ans.push_back({it.first,i});
    return ans;
}

bool Graph::exist(int userId){
    return nameOfUser.find(userId)!=nameOfUser.end();
}

bool Graph::addUser(int userId,string userName){
    if(exist(userId)) return false;
    nameOfUser[userId] = userName;
    adjList[userId];
    return true;
}

bool Graph::removeUser(int userId){
    if(!exist(userId)) return false;
    nameOfUser.erase(userId);
    for(auto id:adjList[userId]) adjList[id].erase(userId);
    adjList.erase(userId);
    return true;
}

bool Graph::addFriend(int userId1, int userId2){
    if(!exist(userId1) || !exist(userId2) || userId1==userId2 || adjList[userId1].find(userId2)!=adjList[userId1].end()) return false;
    adjList[userId1].insert(userId2);
    adjList[userId2].insert(userId1);
    return true;
}

bool Graph::removeFriend(int userId1,int userId2){
    if(!exist(userId1) || !exist(userId2) || userId1==userId2) return false;
    adjList[userId1].erase(userId2);
    adjList[userId2].erase(userId1);
    return true;
}

void Graph::printGraph(){
    for(auto& it:adjList){
        if(it.second.empty()){
            cout<<it.first<<endl;
            continue;
        }
        string list = "";
        for(int i:it.second) list = list + to_string(i) + ",";
        list.pop_back();
        cout<<it.first<<"->"<<list<<endl;
    }
}