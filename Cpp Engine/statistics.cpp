#include <iostream>
#include "graph.h"
using namespace std;

int Graph::totalUsers(){
    return nameOfUser.size();
}

int Graph::totalConnections(){
    int ans = 0;
    for(auto it:adjList) ans+=it.second.size();
    ans/=2;
    return ans;
}

double Graph::averageFriends(){
    if(nameOfUser.empty()) return 0;
    double ans = 0;
    for(auto it:adjList) ans+=it.second.size();
    ans /= nameOfUser.size();
    return ans;
}

int Graph::mostConnectedUser(){
    int ans = -1;
    for(auto it:adjList){
        if(ans==-1) ans = it.first;
        else if(it.second.size()>adjList[ans].size()) ans = it.first;
    }
    return ans;
}