#include<bits/stdc++.h>
using namespace std;

/*
Given an adjacency list of a graph adj  of V no. of vertices having 0 based index. Check whether the graph is bipartite or not.
 

Example 1:

Input: 

Output: 1
Explanation: The given graph can be colored 
in two colors so, it is a bipartite graph.
Example 2:

Input:

Output: 0
Explanation: The given graph cannot be colored 
in two colors such that color of adjacent 
vertices differs. 
 

Your Task:
You don't need to read or print anything. Your task is to complete the function isBipartite() which takes V denoting no. of vertices and adj denoting adjacency list of the graph and returns a boolean value true if the graph is bipartite otherwise returns false.
 

Expected Time Complexity: O(V + E)
Expected Space Complexity: O(V)

Constraints:
1 ≤ V, E ≤ 105


*/

class Solution {
public:


    bool bfs(int node , int V , vector<int>g[] , int color[]){
        queue<int>q;
        q.push(node);
        color[node] = 0;
        
        while(!q.empty()){
            int front = q.front();
            q.pop();
            for(auto nbr:g[front]){
                // if nbr is not colored then colored it will opposite of it's parent color
                if(color[nbr]==-1){
                    color[nbr] = !color[front];
                    q.push(nbr);
                }
                // if it is alreay colored as same as the color of it's parent then retur false otherwise cotinue with bfs
                else if(color[nbr]==color[front]){
                    return false;
                }
            }
        }
        return true;
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    int color[V];
	    for(int i=0;i<V;i++)color[i]=-1;
	    for(int i=0;i<V;i++){
	        if(color[i]==-1){
	            if(bfs(i,V , adj , color)==false) return false;
	        }
	    }
	    return true;
	    
	}

};

/*
Biparatite Graph : Color the graph with 2 colors such that no adjacent nodes have same colour

Note 1 : Linear Graph with no cycle are always Bipartite graph
Note 2 : Any Grpahs with even cycle length can also be Bipartite Graph 
Note 3 : any graphs with odd length cycle can never be Bipartitite 

*/

// graph is 0 based indexing 
bool Bipartite_using_bfs( int start  , int V , vector<int>adj[] , int color[]){
    queue<int>q;
    q.push(start);
    
    color[start] =0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto it : adj[node]){
            // if the adjacent/neighbour  node is yet not colored then colored it with opposite color of node  
            if(color[it]==-1){
             color[it] = !color[node];
             q.push(it);
            }
            // is adjacent/neighbour guy having the same colour 
            // someonr did color it on some other path
            else if(color[it]==color[node]) return false;

        }
    }

    return true;

}
int main(){
    /*
     colors - 0 and 1  , -1 means no color
    */
   int V;
   vector<int>g[V];
   int color[V] ={-1};
   for(int i=0;i<V;i++){
    if(color[i]==-1){
        if(Bipartite_using_bfs(i,V,g , color)==false) cout<<"Graph is not Bipartite"<<endl;
        
    }
   }
   cout<<"Graph is Bipartite"<<endl;

return 0;
}