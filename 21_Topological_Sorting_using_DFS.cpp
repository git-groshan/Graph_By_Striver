#include<bits/stdc++.h>
using namespace std;

/*
What is Topological Sorting ?
-It is only possible in Directed Acyclic Graph (DAG). 
- It is linear ordering of vertices such that if there is a edge between u & v ,u appears before v in that ordering
Why possible only in DAG?
Beacuse in undirected graph there is edge between u & v and vice versa then it can not be possible to decide which comed before u or v 
why acyclic?
 Similary we can't decide which comes before in cyclic graph also (that last edge which make graph completes )

*/

/*
Approach : take a stack and before exiting the dfs for a node put that into stack .


*/
/*
what is the intitution behind this ?

 1->2->3->4 -> 5
          |
          6 
*/



/*
T.C = O(O + V)
S.C = O(V)
*/

void connectEdge(int u  , int v , vector<int>g[]){
    g[u].push_back(v);
}

void topologicalSortingUsingDFS(int node , int vis[] , stack<int>&st , vector<int>adj[]){

    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            topologicalSortingUsingDFS(it , vis , st , adj);
        }
    }
    // before exiting the dfs of the node push that into stack 
    st.push(node);

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
   stack<int>st;
   for(int i=0;i<V;i++){
    if(!vis[i]){
        topologicalSortingUsingDFS(i , vis , st , g);
    }
   }
   vector<int>topologicalOrdering;
   while(!st.empty()){
    topologicalOrdering.push_back(st.top());
    st.pop();
   }
   cout<<"Topological ordering is "<<endl;
   for(int i=0;i<topologicalOrdering.size();i++){
    cout<<topologicalOrdering[i]<<" ";
   }

return 0;
}