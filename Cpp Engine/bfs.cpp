#include <iostream>
#include <queue>
#include "graph.h"
using namespace std;

vector<int> Graph::bfs(int start){
    queue<int> q;
    q.push(start);
    set<int> visited;
    visited.insert(start);
    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto nei:adjList[node]){
            if(visited.find(nei)==visited.end()){
                visited.insert(nei);
                q.push(nei);
            }
        }
    } 
    return ans;
}