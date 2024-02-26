#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n=0,m=0;
    cin>>n>>m;

    unordered_map<int,list<int>> adj;
    int inDegree[n+1] = {};

    for(int i=0; i<m; i++){
        int u = 0;
        int v = 0;
        cin>>u>>v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    int cnt = 0;

    for(int i=1; i<=n; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();
        cnt++;

        for(auto neighbour : adj[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    if(cnt == n) cout<<"Cycle not present"<<endl;
    else cout<<"Cycle is Present"<<endl;

   return 0;
}
