#include <iostream>
#include <stack> 
#include "graph.h"
using namespace std;

vector<int> Graph::dfs(int start){
    set<int> visited;
    stack<int> st;
    vector<int> ans;
    st.push(start);
    visited.insert(start);
    while(!st.empty()){
        int node = st.top();
        st.pop();
        ans.push_back(node);
        for(auto nei:adjList[node]){
            if(visited.find(nei)==visited.end()){
                st.push(nei);
                visited.insert(nei);
            }
        }
    }
    return ans;
}