#include<bits/stdc++.h>
using namespace std;


void connectEdge(int u , int v , vector<int>g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}

void dfs(int V , vector<int>g[] , int startingNode , vector<bool>&vis){

    if(!vis[startingNode]){
        vis[startingNode] = true;
        for(auto nbr:g[startingNode]){
            if(!vis[nbr])
            dfs(V , g , nbr,vis);
        }
        
    }



}


// connected undirected graph and starting index is 0
void DFS(int node , vector<int>adj[] , int vis[] , vector<int>&ls){
    vis[node]=1;
    ls.push_back(node);

    // traverse to all its neighbours
    for(auto it :adj[node]){
        if(!vis[it]){
            DFS(it , adj , vis , ls);
        }
    }
}


void dfs_by_luv(int vertex , vector<int>g[] , vector<bool>&vis){
    // section 1
    /*
    Take action on vertex after entering the vertex
    */
//    if(vis[vertex]) return;
   vis[vertex]=true;
    for(auto &child :g[vertex]){
        // section 2
        /* 
        take action on child before entering the child node
        */

       if(!vis[child])
            dfs_by_luv(child , g , vis);
        //section 3
        /*
        Take action on child after exiting the child node
        */
    }
    // section 4
    /*take action on vertext before exiting the vertex*/

}
vector<int> dfsOfGraph(int V , vector<int>adj[]){
    int vis[V]={0};
    int start = 0;
    vector<int>ls;
    DFS(start , adj , vis , ls);
    return ls;
    
}

int main(){

    vector<int>g[9];
    connectEdge(1,2,g);
    connectEdge(1,3,g);
    connectEdge(2,5,g);
    connectEdge(2,6,g);
    connectEdge(3,4,g);
    connectEdge(3,7,g);
    connectEdge(8,7,g);
    connectEdge(4,8,g);

    vector<bool>vis(9,false);
    dfs(8 , g , 1 , vis);
    for(int i=1;i<=8;i++){
        if(!vis[i]) cout<<"dfs is wrong";
    }
    cout<<"Dfs is succesfull";



    return 0;
}

/**
 * S.C - O(N) + O(N) + O(N)
 * T.C - O(N) + O(2E)
 * 
*/