#include<bits/stdc++.h>
using namespace std;
/*

Given a boolean 2D matrix grid of size n * m. You have to find the number of distinct islands where a group of connected 1s (horizontally or vertically) forms an island. Two islands are considered to be distinct if and only if one island is not equal to another (not rotated or reflected).

Example 1:

Input:
grid[][] = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}}
Output:
1
Explanation:
grid[][] = {{1, 1, 0, 0, 0}, 
            {1, 1, 0, 0, 0}, 
            {0, 0, 0, 1, 1}, 
            {0, 0, 0, 1, 1}}
Same colored islands are equal.
We have 2 equal islands, so we 
have only 1 distinct island.

Example 2:

Input:
grid[][] = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}}
Output:
3
Explanation:
grid[][] = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}}
Same colored islands are equal.
We have 4 islands, but 2 of them
are equal, So we have 3 distinct islands.

Your Task:

You don't need to read or print anything. Your task is to complete the function countDistinctIslands() which takes the grid as an input parameter and returns the total number of distinct islands.

Expected Time Complexity: O(n * m)
Expected Space Complexity: O(n * m)

Constraints:
1 ≤ n, m ≤ 500
grid[i][j] == 0 or grid[i][j] == 1



*/


void dfs(int row , int col , vector<vector<int>>&grid , vector<vector<bool>>&vis , vector<pair<int,int>>&vec , int baseI , int baseJ ){
    vis[row][col]=true;
    vec.push_back({row - baseI , col  - baseJ});
    int delrow[] = {-1,1,0,0};
    int delcol[] = {0,0,-1,1};
    int n = grid.size() , m = grid[0].size();
    for(int k=0;k<4;k++){
        int nrow = row + delrow[k];
        int ncol = col + delcol[k];
        if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and grid[nrow][ncol]==1 and !vis[nrow][ncol]){
            dfs(nrow,ncol,grid , vis , vec , baseI ,baseJ);
        }
    }

}
int countDistinctIslands(vector<vector<int>>&grid){
    int n = grid.size() , m = grid[0].size();
    // bool vis[n][m]={false};
    vector<vector<bool>>vis(n , vector<bool>(m,false));
    set<vector<pair<int,int>>>st;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!vis[i][j] && grid[i][j]==1){
                vector<pair<int,int>>vec;
                dfs(i,j,grid,vis,vec , i , j);
                st.insert(vec);
            }
        }

    }
    return st.size();
}
int main(){
    /*
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
            {1, 1, 0, 0, 0},
            {0, 0, 0, 1, 1},
            {0, 0, 0, 1, 1}};
    */
   
    vector<vector<int>> grid = {{1, 1, 0, 1, 1},
            {1, 0, 0, 0, 0},
            {0, 0, 0, 0, 1},
            {1, 1, 0, 1, 1}};

    /*
       vector<vector<int>> grid = {{1, 1, 0, 1, 1}, 
            {1, 0, 0, 0, 0}, 
            {0, 0, 0, 0, 1}, 
            {1, 1, 0, 1, 1}};

    */
    cout<<"No of Distinct Islands are "<<countDistinctIslands(grid)<<endl;

return 0;
}