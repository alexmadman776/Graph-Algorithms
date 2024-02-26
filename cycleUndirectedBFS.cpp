#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isCyclePresent(int node,unordered_map<int,list<int>> &adj,int visited[],int V){
    vector<int> parent(V+1, -1);
    visited[node] = 1;
    
    queue<int> q;
    q.push(node);

    while(!q.empty()){
        int front = q.front();
        q.pop();

        for(auto nextNode : adj[front]){
            if(!visited[nextNode]){
                visited[nextNode] = 1;
                parent[nextNode] = front;
                q.push(nextNode);
            }else if(parent[front] != nextNode){
                return true;
            }
        }

    }
    return false;
}

int main()
{
    int V = 0,E = 0;
    cin>>V>>E;
    unordered_map<int,list<int>> adj;
    int visited[V+1] = {0,};

    for(int i=0; i<E; i++){
        int u=0,v=0;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool ans = false;
    // using a for loop to manage disconnected component of  a graph
    for(int i=1; i<V+1; i++){
        if(!visited[i]){
            ans =  ans | isCyclePresent(i,adj,visited,V);
        }
    }

    cout<<"ans : "<<ans<<endl;
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No "<<endl;

   return 0;
}