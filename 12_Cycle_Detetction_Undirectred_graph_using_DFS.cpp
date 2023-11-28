#include<bits/stdc++.h>
using namespace std;

void connectEdges(int u , int v , vector<int>g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}
bool detectCycleUsingDFS(int src , vector<int>g[] ,vector<bool>&vis){
    vis[src] = true;
    for(auto nbr:g[src]){
        if(!vis[nbr]) 
            if(detectCycleUsingDFS(nbr , g , vis)==true) return true;
        else if(nbr!=src) return true;

    }
return false;
}
int main(){
vector<int>g[8];
connectEdges(1,2,g);
connectEdges(2,5,g);
connectEdges(5,7,g);
connectEdges(7,6,g);
connectEdges(6,3,g);
connectEdges(3,1,g);
connectEdges(3,4,g);
vector<bool>vis(8,false);
 cout<<detectCycleUsingDFS(1,g,vis);
return 0;
}