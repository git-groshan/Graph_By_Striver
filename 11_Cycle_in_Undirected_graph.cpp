#include<bits/stdc++.h>
using namespace std;

void connectEdges(int u , int v , vector<int>g[]){
    g[u].push_back(v);
    g[v].push_back(u);
}
/*
bool detectCycleUsingBFS(vector<int>g[] , int node , int V){
    queue<int>q;
    q.push(node);
    vector<bool>vis(V,false);
    while(!q.empty()){
        auto n = q.front();
        q.pop();
        vis[n]=true;
        for(auto nbr:g[n]){
            if(!vis[nbr]) q.push(nbr); // this will always be false after we try to process second node bcz it will check for it's parent which will be visited 
            // hence we need to keep track of parent in this
            else return true;
        }
    }
    return false;
}
*/

bool CycleDetectionUsingBFS(vector<int>g[] , int node  , int V){
    queue<pair<int,int>>q;
    q.push({node,-1});
    vector<bool>vis(V,false);
    // vis[node] = true;

    while(!q.empty()){
        auto front = q.front();
        int curNode = front.first;// this will act as a parent for nbr node 
        int parent = front.second;
        q.pop();
        vis[curNode] = true;
        for(auto nbr : g[curNode]){
           if(!vis[nbr]) q.push({nbr,curNode});
           else if(parent!=nbr) return true;
        }
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

// if(detectCycleUsingBFS(g,1,8)) cout<<"Cycle Present";
// else cout<<"Cycle Not Present ";
if(CycleDetectionUsingBFS(g,1,8)) cout<<"Cycle Present";
else cout<<"Cycle Not Present";
return 0;
}
/*
T.C = O(N ) + O(2*E)
S.C = O(N)
*/