#include<bits/stdc++.h>
using namespace std;

// No of Provinces == No of Connected component == No of DFS calls 


void connectEdges(int u , int v , vector<int>g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}
void dfs(int node , vector<int>g[] , vector<int>&vis){
    if(vis[node]) return;

    vis[node] = true;
    for(auto nbr:g[node]){
        if(!vis[nbr]) dfs(nbr , g , vis);
    }
}



int main(){
    int V = 9;
    vector<int> g[V];
    connectEdges(1,2,g);
    connectEdges(2,3,g);
    connectEdges(4,5,g);
    connectEdges(5,6,g);
    connectEdges(7,8,g);

vector<int>vis(V,0);
int noOfProvinces = 0;
for(int i=1;i<V;i++){
    if(!vis[i]) {
        noOfProvinces++;
        dfs(i , g,vis);
    }
    
}
cout<<"noOfProvinces is "<<noOfProvinces<<endl;

    return 0;
}
/*
T.C = O(N) + O(V + 2E)
*/