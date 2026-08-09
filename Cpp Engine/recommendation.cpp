#include <iostream>
#include "graph.h"
using namespace std;

vector<int> Graph::mutualFriends(int user1,int user2){
    set<int> *small = &adjList[user1];
    set<int> *big = &adjList[user2];
    vector<int> ans;
    if(small->size()>big->size()) swap(small,big); 
    for(auto it:*small) if(big->find(it)!=big->end()) ans.push_back(it);
    return ans;
}

vector<int> Graph::recommendFriends(int userId){
    map<int,int> common;
    for(int friendId : adjList[userId]) {
        for(int candidate : adjList[friendId]) {
            if(candidate != userId && adjList[userId].find(candidate) == adjList[userId].end()) common[candidate]++;
        }
    }
    vector<int> ans;
    for(auto it:common) ans.push_back(it.first);
    sort(ans.begin(),ans.end(),[&](int a,int b){
        return common[a]>common[b];
    });
    return ans;
}

