#include<bits/stdc++.h>
using namespace std;


/**
 * Given n (no of nodes) and m(no of edges) of undirected graphs, following m lines represents edges
 * 
 * 2 ways to store the graph
 * a) matrix way  b) list way
 * 
 * Adjacency Matrix way - Create a matrix of n x n (if nodes are 0 based) and
 * Space - (N x N)
 * 
 * Adjacency List way - vector<int> adj[n]  --- array of vector of type integer 
 * Motive of list is to store neigbours of node
 * space - (2 x E)
 * 
*/

int main(){

    int n , m;
    cin>>n>>m;
    int adj_mat[n+1][n+1]; // adjacency matrix without any weight;
    vector<int> adj_list[n+1];// adjacency list without any weight or having unit weights

    vector<pair<int,int>>graph[n+1]; // adjacency list to store the weights of graphs 

    for(int i=0;i<m;i++){
        int u , v;
        cin>>u>>v;
        // adj_mat way of storing 
        adj_mat[u][v]=1;
        adj_mat[v][u]=1;
        // way to store if weights are given of undirected graph
        /*
         adj_mat[u][v]= wt;
        adj_mat[v][u]=wt;
        */
        
        // adj_list way of storing 
        adj_list[u].push_back(v);
        // no need to store below one if there is a directed graph
        adj_list[v].push_back(u);

        // way to store in adj_list if weights of graphs are given 
        /*
        graph[u].push_back({v,wt});
        graphs[v].push_back({u,wt});
        */
    }
}