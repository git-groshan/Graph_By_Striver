#include<bits/stdc++.h>
using namespace std;
// Breadth First Search or level order Traversal 
 

vector<int> BFS(vector<int>g[] , int Startingnode , int n){
    queue<int>q;
    q.push(Startingnode);
    vector<int>bfs;
    vector<bool>vis(n , false);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        vis[node]=true;
        bfs.push_back(node);
        for(auto nbr:g[node]){
            if(!vis[nbr])
                q.push(nbr);
        }
    
    
    }
    return bfs;
    
}
int main(){
    vector<int>g[10];
    g[1].push_back(2);
    g[1].push_back(6);
    g[2].push_back(3);
    g[2].push_back(4);
    g[6].push_back(7);
    g[6].push_back(9);
    g[4].push_back(5);
    g[7].push_back(8);
    g[5].push_back(8);

    vector<int> bfs = BFS(g,1,10);
    for(auto node : bfs) cout<<node<<" ";
    cout<<endl;



    return 0;
}
/*
S.C = O(3N)==O(N)
T.C = O(N) + O(2E)-->No of total degrees == No of Neighbours 
*/