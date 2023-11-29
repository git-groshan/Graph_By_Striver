#include<bits/stdc++.h>
using namespace std;
/*
A directed graph of V vertices and E edges is given in the form of an adjacency list adj. Each node of the graph is labelled with a distinct integer in the range 0 to V - 1.

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node.

You have to return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

Example 1:

Input:


Output:
2 4 5 6
Explanation:
The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no 
outgoing edges from either of them. 
Every path starting at nodes 2, 4, 5, and 6 all 
lead to either node 5 or 6.
Example 2:

Input:


Output:
3
Explanation:
Only node 3 is a terminal node, and every path 
starting at node 3 leads to node 3.
Your Task:
You don't need to read or print anything. Your task is to complete the function eventualSafeNodes() which takes an integer V denoting no. of vertices and adj denoting adjacency list of the graph and returns an array of safe nodes.

Expected Time Complexity: O(V + E)

Expected Space Complexity: O(V)

Constraints:

1 <= V <= 104
0 <= E <= 104
The graph won't contain self loops.
Each node in the graph has a distinct value in the range 0 to V - 1.

*/

/*
Anyone who is part of cycle  can not be safe node 
anyone who leads to a cycle i.e an outgoing edge from that node to any node which are part of cycle , Can not be safe nodes 

*/

/*
Approach : We will be using cycle detection in directed graph . for each node we will call a dfs and if we don't get any cycle then the nodes which are part of the path are eventually safe node 
beacuse they will end up to a terminal node 
*****  ----> At the end whichever nodes are visited and pathVisted will not be eventual safe node.
Take a dry run by your own 
*/


void connectEdge(int u , int v , vector<int>g[]){
    g[u].push_back(v);
}
bool isCycleInDirectedGraph(int node , vector<int>g[] , vector<bool>&vis , vector<bool>&pathVis , int check[]){
    vis[node] = true;
    pathVis[node] = true;
    check[node] = 0;
    for(auto it : g[node]){
        if(!vis[it]){
            if(isCycleInDirectedGraph(it , g , vis , pathVis , check) == true) {
            check[node] = 0;
            return true;
            }
        }
        else{
            if(pathVis[it]== true) {
            check[node] = 0; 
            return true;
            }
        }
    }
    check[node]=1; // means there is no cycle detetcted hence it's a safe node 
    pathVis[node] = false;
    return false;
}

int main(){

    int V = 11;
vector<int>g[V];
connectEdge(0,1,g);
connectEdge(1,2,g);
connectEdge(2,3,g);
connectEdge(3,4,g);
connectEdge(3,7,g);
connectEdge(4,5,g);
connectEdge(5,6,g);
connectEdge(7,5,g);
connectEdge(8,2,g);
connectEdge(8,9,g);
connectEdge(9,10,g);
connectEdge(10,8,g);

vector<bool>vis(V, false);
vector<bool>pathVis(V,false);
int check[V]={0};

for(int i=0;i<V;i++){
    if(!vis[i]) isCycleInDirectedGraph(i,g , vis, pathVis , check);
}

return 0;
}