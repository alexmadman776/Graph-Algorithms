#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void bfs(int root,unordered_map<int,vector<int>> &adj,unordered_map<int,bool> &visited,vector<int> &path){

    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int front = q.front();
        visited[front] = true;
        q.pop();
        path.push_back(front);
        // cout<<front<<" ";

        for(int i=0; i<adj[front].size(); i++){
            int neighbour = adj[front][i];
            if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = true;
            }
        }
        
    }
    
}
// 0 1 2 3 4 7 5 6
int main()
{
    unordered_map<int,vector<int>> adj;
    unordered_map<int,bool> visited;
    vector<int> path;

    int n = 0;
    int m = 0;
    cout<<"Enter the number of nodes"<<endl;
    cin>>n;
    cout<<"Enter the number of edges"<<endl;
    cin>>m;
    cout<<"Enter the edges"<<endl;

    for(int i=0; i<m; i++){
        // we are considering a directed graph
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);    
    }

    for(int i=0; i<n; i++){
        visited[i] = false;
    }

 

    for(int i=0; i<n; i++){
        if(!visited[i]){
            bfs(i,adj,visited,path);
        }
    }

    
    for(int i=0; i<n; i++){
        cout<<path[i]<<" ";
    }


   return 0;
}
