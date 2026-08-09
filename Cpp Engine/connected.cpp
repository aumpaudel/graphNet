#include <iostream>
#include "graph.h"
using namespace std;

vector<vector<int>> Graph::connectedComponents(){
    set<int> visited;
    vector<vector<int>> ans;
    for(auto it:nameOfUser){
        if(visited.find(it.first)!=visited.end()) continue;
        queue<int> q;
        q.push(it.first);
        visited.insert(it.first);
        vector<int> subans;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            subans.push_back(node);
            for(auto nei:adjList[node]){
                if(visited.find(nei)==visited.end()){
                    visited.insert(nei);
                    q.push(nei);
                }
            }
        } 
        ans.push_back(subans);
    }
    return ans;
}

int Graph::componentCount(){
    return connectedComponents().size();
}