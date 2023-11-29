#include<bits/stdc++.h>
using namespace std;

/*
Note : Cycle detection technique using DFS in Undirected graph will not work here. 

Logic : If we encountered a already visited node on the way of the  same path then it contains cycle
i.e on the same path , node has to be visited again

Approach : We will take visted array and a pathVis array or simply stack to check if the already visited node is in the stack or pathVis then only the cycle is detected
Note : if we encounter a node which is already visited and is in the stack or pathVis then only Cycle is possible 



*/

// T.C = O(V + E)
// S.C = O(2V)
void connectEdge(int u , int v , vector<int>g[]){
    g[u].push_back(v);
}

bool isCycleInDirectedGraph(int node , vector<int>g[] , vector<bool>&vis , vector<bool>&pathVis){
    vis[node] = true;
    pathVis[node] = true;
    for(auto it : g[node]){
        if(!vis[it]){
            if(isCycleInDirectedGraph(it , g , vis , pathVis) == true) return true;
        }
        else{
            if(pathVis[it]== true) return true;
        }
    }
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
// connectEdge(10,8,g);

vector<bool>vis(V, false);
vector<bool>pathVis(V,false);
for(int i=0;i<V;i++){
    if(!vis[i]){
        if(isCycleInDirectedGraph(i, g , vis , pathVis) == true) cout<<"CYcle present"<<endl;
    }
}

// cout<<"Cycle not present "<<endl;


return 0;
}