#include <iostream>
#include <queue> 
#include "graph.h"
using namespace std;

pair<vector<int>,int> Graph::shortestPath(int start,int end){
    queue<int> q;
    q.push(start);
    map<int,int> dist;
    map<int,int> parent;
    dist[start] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int nei:adjList[node]){
            if(dist.find(nei)==dist.end()){
                dist[nei] = dist[node]+1;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }
    if(dist.find(end) == dist.end()) return {};
    int ans2 = dist[end];
    vector<int> ans1; 
    int x = end;
    ans1.push_back(x);
    while(x!=start){
        x = parent[x];
        ans1.push_back(x);
    }
    reverse(ans1.begin(), ans1.end());
    return {ans1,ans2};
}