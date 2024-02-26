#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>

class Graph{
    public:
        unordered_map<T,list<T>>  adj;

        void addEdge(T u,T v,bool dir){
            // check directed or undirectedgraph
            // dir = 0 ->undirected
            // dir = 1 ->directed

            // create an edge from u to v
            adj[u].push_back(v);

            if(dir == 0){
                adj[v].push_back(u);
            }
        }
        void printAdjList(){
            for(auto iterator: adj){
                cout<<iterator.first<<"->";
                for(auto item: iterator.second){
                    cout<<item<<",";
                }
                cout<<endl;
            }
        }
};

int main()
{
    int n=0;
    cout<<"Enter the number of nodes in the graph"<<endl;
    cin>>n;
    int m=0;
    cout<<"Enter the number of Edges in the graph"<<endl;
    cin>>m;

    Graph<int> g;
    for(int i=0; i<m; i++){
        int u=0,v=0;
        cin>>u>>v; 
        // creating a undirected graph
        g.addEdge(u,v,0);
    }

    g.printAdjList();

   return 0;
}