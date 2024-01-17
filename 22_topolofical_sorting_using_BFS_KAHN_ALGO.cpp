#include<bits/stdc++.h>
using namespace std;

/*
Topological Sorting : Vertices such that if there is an edge between u & v , u appears before v in the ordering.
Only valid in Directed Acyclic Graph (DAG)

*/

/*
We will use Indegree(No of incoming edges ) array.
In DAG for topological sorting , there must be atleast one node whose indegree is 0 
1. Insert all node whose indegree 0 in the queue. and decrease there indegree by 1 
2. take them out of the queue and decrease the indegree of it's neigbour by 1 
*/

/*
T.C = O( V + E)
S.C = O(V)
*/
void connectEdge(int u  , int v , vector<int>g[]){
    g[u].push_back(v);
}

int main(){
     int V = 6;
    vector<int>g[V];
    connectEdge(2,3,g);
    connectEdge(3,1,g);
    connectEdge(4,1,g);
    connectEdge(4,0,g);
    connectEdge(5,0,g);
    connectEdge(5,2,g);
    /*
    possible answers :   5 4 2 3 1 0 , 4 5 2 3 1 0

    */
   int vis[V] = {0};
    queue<int>q;
   int indegree[V] = {0};
   for(int i=0;i<V;i++){
    for(auto it : g[i]) indegree[it]++;
   }
   for(int i=0;i<V;i++){
    if(indegree[i]==0)q.push(i);
   }

   vector<int>topo;
   while(!q.empty()){
    int node = q.front();
    q.pop();
    topo.push_back(node);

    for(auto it : g[node]){
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
    }
   }
   cout<<"Topological ordering of graph is "<<endl;
   for(int i=0;i<topo.size();i++) cout<<topo[i]<<" ";
   cout<<endl;


return 0;
}