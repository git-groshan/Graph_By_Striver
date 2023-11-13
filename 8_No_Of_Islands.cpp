#include<bits/stdc++.h>
using namespace std;



bool isSafe(int i , int j , vector<vector<int>>&mat ,vector<vector<int>>&vis ){
    int n = mat.size() , m = mat[0].size();

    return i>=0 && i<n && j>=0 && j<m && mat[i][j]==1 && !vis[i][j];
}


void dfsHelper(int i, int j , vector<vector<int>>&mat , vector<vector<int>>&vis){
    if(vis[i][j]) return;

    vis[i][j]=1;
    for(int delrow = -1;delrow<=1;delrow++){
        for(int delcol=-1;delcol<=1;delcol++){
            int p = i + delrow , q = j + delcol;
            if(isSafe(p,q,mat,vis)){
                dfsHelper(p,q,mat,vis);
            }
        }
    }

}
int  dfs(vector<vector<int>>&mat , vector<vector<int>>&vis){
    int n = mat.size() , m = mat[0].size();
    int noOfIslands = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1 && !vis[i][j]){
                noOfIslands++;
                dfsHelper(i,j,mat,vis);
            }
        }
    }


}




void bfsHelper(int i , int j , vector<vector<int>>&mat , vector<vector<int>>&vis){
    queue<pair<int,int>>q;
    q.push({i,j});

    // int dx[] = {-1 , -1 , 0 , 1 , 1, 1 ,0 , - 1};
    // int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
    while(!q.empty()){
        auto front = q.front();
        q.pop();

        int row = front.first , col = front.second;
        vis[row][col]=1;
        for(int delrow = -1 ;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow = row + delrow;
                int ncol = col + delcol;
                if(isSafe(nrow , ncol , mat , vis)){
                    q.push({nrow ,ncol});
                }
            }
        }
    }
}
int  bfs(vector<vector<int>>&mat, vector<vector<int>>&vis){
        int noOfIslands = 0;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1 && !vis[i][j]){
                        noOfIslands++;
                        bfsHelper(i,j,mat , vis);
                    }
                }
            }
            return noOfIslands;
}

int main(){
    int n = 5, m = 4;
    vector<vector<int>> mat = {{0,1,1,0},
                                {0,1,1,0},
                                {0,0,1,0},
                                {0,0,0,0},
                                {1,1,0,1}};

    vector<vector<int>> vis(n ,vector<int>(m,0));

    // cout<<bfs(mat,vis)<<endl;
    cout<<dfs(mat,vis)<<endl; // not working will check later 
    return 0;

}

/*
S.C = O(N^2)
T.C = O(N^2 )
*/