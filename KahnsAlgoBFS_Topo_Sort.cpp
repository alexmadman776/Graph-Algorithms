#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int main()
{  
    int n = 0,m = 0;
    cin>>n>>m;
    unordered_map<int,list<int>> adj;
    int inDegree[n] = {};
    vector<int> ans;
    for(int i=0; i<m; i++){
        int u=0,v=0;
        cin>>u>>v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i]==0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int front = q.front();
        q.pop();
        ans.push_back(front);

        for(auto neighbour : adj[front]){
            inDegree[neighbour]--;
            if(inDegree[neighbour] == 0) {
                q.push(neighbour);
            }
        }
    }

    for(auto node : ans) cout<<node<<" ";

    return 0;
}

/*
Complexity Analysis: 
 

Time Complexity: O(V+E). 
The outer for loop will be executed V number of times and the inner for loop will be executed E number of times.
Auxiliary Space: O(V). 
The queue needs to store all the vertices of the graph. So the space required is O(V)

Application of Kahn’s algorithm for Topological Sort:   

1.Course sequencing: Courses at universities frequently have prerequisites for other courses. The courses can be scheduled using Kahn’s algorithm so that the prerequisites are taken before the courses that call for them.

2.Management of software dependencies: When developing software, libraries and modules frequently rely on other libraries and modules. The dependencies can be installed in the proper order by using Kahn’s approach.

3.Scheduling tasks: In project management, activities frequently depend on one another. The tasks can be scheduled using Kahn’s method so that the dependent tasks are finished before the tasks that depend on them.

4.Data processing: In data processing pipelines, the outcomes of some processes may be dependent. The stages can be carried out in the right order by using Kahn’s algorithm.

5.Circuit design: In the creation of an electronic circuit, some components may be dependent on the output of others. The components can be joined in the right order by using Kahn’s technique.
*/
 