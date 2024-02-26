#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfsShortestPath(int src,unordered_map<int,list<int>> &adj,int visited[],int parent[]){
    
    visited[src] = 1;
    parent[src] = -1;
    queue<int> q;
    q.push(src);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto neighbour : adj[front]){
            if(!visited[neighbour]){
                visited[neighbour] = 1;
                parent[neighbour] = front;
                q.push(neighbour);
            }
        }

    }



}


int main()
{   
    int n=0,m=0;
    cin>>n>>m;
    unordered_map<int,list<int>> adj;
    int visited[n+1] ={};
    int parent[n+1] = {};
    int src=0,target=0;
    cin>>src>>target;
    for(int i=0; i<m; i++){
        int u=0,v=0;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    bfsShortestPath(src,adj,visited,parent);
    vector<int> ans;
    while(true){
        if(target==-1) break;
        ans.push_back(target);
        target = parent[target];
    }

    reverse(ans.begin(),ans.end());
    
    for(auto node: ans) cout<<node<<" ";


   return 0;
}

