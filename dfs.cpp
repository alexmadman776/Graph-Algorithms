#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

void dfs(int node,unordered_map<int,list<int>> &adj,int visited[],vector<int> &path){
    path.push_back(node);
    visited[node] = 1;
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){
            dfs(neighbour,adj,visited,path);
        }
    }
}

int main()
{
    unordered_map<int,list<int>> adj;
    int n=0,m=0;
    cout<<"Enter the Number of Nodes and Edges "<<endl;
    cin>>n>>m;
    cout<<"Enter the All the Edges"<<endl;
    int visited[n] = {0,};
    vector<vector<int>> ans;
    int components = 0;
    ans.push_back({1});
    for(int i=0; i<m; i++){
        int u = 0;
        int v = 0;
        // We are referring a undirected graph
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=0; i<n; i++){
        if(!visited[i]){
            components++;
            vector<int> path;
            dfs(i,adj,visited,path);
            ans.push_back(path);
        }
    }
    // if some garbage value print try using n insted of path.size()
    ans[0][0] = components;
    for(auto vec : ans){
        for(auto e : vec){
            cout<<e<<" ";
        }
        cout<<endl;
    }
   return 0;
}
/*
9 7
0 1
0 2
0 5
3 6
7 4
4 8
7 8
3
0 1 2 5
3 6
4 7 8

*/ 