#include<bits/stdc++.h>
using namespace std;


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

    bool dfs(int node , int col , int color[] , vector<int>adj[]){
        color[node] = col;
        for(auto it:adj[node]){
            if(color[it]==-1){
                if(dfs(it , !col , color , adj)==false) return false;
            }
            else if(color[it]==col) return false;
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

int main(){

return 0;
}