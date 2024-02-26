#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int src,unordered_map<int,list<int>> &adj,int visited[],int dfsVisited[]){
    visited[src] = 1;
    dfsVisited[src] = 1;

    for(auto neighbour : adj[src]){
        if(!visited[neighbour]){
            bool ans = dfs(neighbour,adj,visited,dfsVisited);
            if(ans) return true;
        }
        else if(dfsVisited[neighbour]){
            return true;
        }
    }
    dfsVisited[src] = 0;
    return false;
}
int main()
{
    int n=0,m=0;
    cin>>n>>m;
    unordered_map<int,list<int>> adj;
    int visited[n+1] = {};
    int dfsVisited[n+1] ={};

    for(int i=0; i<m; i++){
        int u=0,v=0;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    bool cycle = false;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cycle = cycle | dfs(i,adj,visited,dfsVisited);
        }
    }

    if(cycle) cout<<"Yes";
    else cout<<"No";

   return 0;
}