#include <iostream>
#include "graph.h"
using namespace std;

bool Graph::exist(int userId){
    return nameOfUser.find(userId)!=nameOfUser.end();
}
void Graph::addUser(int userId,string userName){
    if(exist(userId)) return;
    nameOfUser[userId] = userName;
    adjList[userId];
}
void Graph::removeUser(int userId){
    if(!exist(userId)) return;
    nameOfUser.erase(userId);
    for(auto id:adjList[userId]) adjList[id].erase(userId);
    adjList.erase(userId);
}
void Graph::addFriend(int userId1, int userId2){
    if(!exist(userId1) || !exist(userId2)) return;
    adjList[userId1].insert(userId2);
    adjList[userId2].insert(userId1);
}
void Graph::removeFriend(int userId1,int userId2){
    if(!exist(userId1) || !exist(userId2)) return;
    adjList[userId1].erase(userId2);
    adjList[userId2].erase(userId1);
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