#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void topologicalDfs(int src,unordered_map<int,list<int>> &adj,int visited[],stack<int> & st){
    visited[src] =1;

    for(auto neighbour : adj[src]){
        if(!visited[neighbour]){
            topologicalDfs(neighbour,adj,visited,st);
        }
    }

    st.push(src);               

}

int main()
{
    int n=0,m=0;
    cin>>n>>m;
    unordered_map<int,list<int>> adj;
    int visited[n] ={};
    stack<int> st;
    for(int i=0; i<m; i++){
        int u=0,v=0;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            topologicalDfs(i,adj,visited,st);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
   return 0;
}

