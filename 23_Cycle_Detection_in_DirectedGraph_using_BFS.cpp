#include<bits/stdc++.h>
using namespace std;

/*
using DFS we have used Visited and PathVisited array. In backtracking we reset the pathvis
But this is not possible in BFS
So here we can use Khan's Algo which is used for DAG

*/

/*
Logic: Try to write the topological sorting of graph it is not possible to write it then it's a Directed Cyclic graph
Note : if the topo sort has N element then it is DAG otherwise not a DAG
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

//    vector<int>topo;
    int countOfTopoSortNode=0;
   while(!q.empty()){
    int node = q.front();
    q.pop();
    // topo.push_back(node);
    countOfTopoSortNode++;

    for(auto it : g[node]){
        indegree[it]--;
        if(indegree[it]==0) q.push(it);
    }
   }
//    cout<<"Topological ordering of graph is "<<endl;
//    for(int i=0;i<topo.size();i++) cout<<topo[i]<<" ";
//    cout<<endl;

if(countOfTopoSortNode==V) cout<<"It's a DAG"<<endl;
else cout<<"Not a DAG i.e there exist a cycle "<<endl;


return 0;
}