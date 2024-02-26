#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool dfs(int src,unordered_map<int,list<int>> &adj,int visited[],int parent){

    visited[src] = 1;
    bool ans = false;
   
    for(auto neighbour : adj[src]){
        
        if(!visited[neighbour]){
            visited[neighbour] = 1;
            ans = dfs(neighbour,adj,visited,src);
            if(ans) return true;
        }
        else if(neighbour != parent){
            return true;
        }
    }

    return false;
}
int main()
{
    int n =0,m=0;
    cin>>n>>m;
    // creating a adjency list
    unordered_map<int,list<int>> adj;
    int visited[n+1] = {};
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // to tackle disconnected components of list running loop over all the vertices
    bool cycle = false;
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            cycle = cycle | dfs(i,adj,visited,-1);
        }
    }

    if(cycle) cout<<"Yes";
    else
    cout<<"No";

   return 0;
}