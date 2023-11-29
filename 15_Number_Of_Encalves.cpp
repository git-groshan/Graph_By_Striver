#include<bits/stdc++.h>
using namespace std;
/*
// PROBLEM STATEMENT 

You are given an n x m binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.

A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.

Find the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

Example 1:

Input:
grid[][] = {{0, 0, 0, 0},
            {1, 0, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 0}}
Output:
3
Explanation:
0 0 0 0
1 0 1 0
0 1 1 0
0 0 0 0
The highlighted cells represents the land cells.
Example 2:

Input:
grid[][] = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}}
Output:
4
Explanation:
0 0 0 1
0 1 1 0
0 1 1 0
0 0 0 1
0 1 1 0
The highlighted cells represents the land cells.
Your Task:

You don't need to print or input anything. Complete the function numberOfEnclaves() which takes a 2D integer matrix grid as the input parameter and returns an integer, denoting the number of land cells.

Expected Time Complexity: O(n * m)

Expected Space Complexity: O(n * m)

Constraints:

1 <= n, m <= 500
grid[i][j] == 0 or 1

*/

/*
Approch : It is similar to surrounded regions problem . Start DFS from the corners and check if there is a land then mark all the connect land component as visted . 
At the end the no of not visited lands will be the answer
*/


void dfs(int i , int j , vector<vector<int>>&grid ,  vector<vector<bool>>&vis , int dx[] , int dy[]){

        vis[i][j]=true;
        int n = grid.size() , m = grid[0].size();
        for(int k=0;k<4;k++){
            int nx = i + dx[k];
            int ny = j + dy[k];

            if(nx>=0 and nx<n and ny>=0 and ny<m and grid[nx][ny]==1 and !vis[nx][ny])
            dfs(nx , ny , grid , vis , dx , dy);
        }

    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>>vis( n , vector<bool>(m , false));
        int dx[] = {-1,1,0,0};
        int dy[] = {0,0,-1,1};

        // first and last columns
        for(int i=0;i<n;i++){
            if(!vis[i][0] and grid[i][0] == 1) dfs(i,0,grid , vis , dx ,dy);
            if(!vis[i][m-1] and grid[i][m-1]==1) dfs(i,m-1 , grid , vis , dx , dy);
        }

        // first and last row
        for(int j=0;j<m;j++){
            if(!vis[0][j] and grid[0][j]==1) dfs(0,j,grid , vis , dx , dy);
            if(!vis[n-1][j] and grid[n-1][j]==1) dfs(n-1 , j , grid , vis , dx , dy);
        }


        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] and grid[i][j]==1) ans++;
            }
        }

        return ans;
    }

    int numEnclavesUsingBFS(vector<vector<int>>& grid) {
        
        int dir_x[4] = {1, -1, 0, 0};
        int dir_y[4] = {0, 0, 1, -1};
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0 || vis[i][j]) 
                    continue;
                int cells = 0; 
                bool enclosed = true;   
                queue<pair<int, int>> q({{i, j}});
                vis[i][j] = true;
                while(!q.empty()){
                    auto front = q.front();
                    q.pop();
                    cells++;
                    for(int k = 0; k < 4; k++){
                        int dy = front.first + dir_y[k];
                        int dx = front.second + dir_x[k];
                        if(dx < 0 || dx >= n || dy < 0 || dy >= m) { 
                            enclosed = false;
                            continue;                            
                        }
                        if(vis[dy][dx]) continue;
                        if(grid[dy][dx] == 0) continue;
                        vis[dy][dx] = true;
                        q.push({dy, dx});
                    }
                }
                if(enclosed) 
                    ans += cells;
            }
        }
        return ans;
    }

    int numEnclavesBFS_Striver(vector<vector<int>>&grid){
        int n = grid.size() , m = grid[0].size();
        vector<vector<bool>>vis(n , vector<bool>(m,false));
        // putting the corner 1's in queue
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
           if(i==0 or j==0 or i==n-1 or j == m-1){
                if(grid[i][j]==1){
                    q.push({i,j});
                    vis[i][j] = true;
                }
            }
        }
        }
        int delrow[] = {-1,1,0,0};
        int delcol[] = {0,0,-1,1};
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int nrow = row + delrow[k];
                int ncol = col + delcol[k];
                if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and !vis[nrow][ncol] and grid[nrow][ncol]==1 ){
                    q.push({nrow,ncol});
                    vis[nrow][ncol]=1;
                }
            }
            
        }

        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 and !vis[i][j]) ans++;
            }
        }
    return ans;
    }

int main(){

    vector<vector<int>>grid = {{0, 0, 0, 1},
            {0, 1, 1, 0},
            {0, 1, 1, 0},
            {0, 0, 0, 1},
            {0, 1, 1, 0}};

    cout<<"Number of Enclaves are " << numEnclaves(grid)<<endl;
    cout<<"Number of Enclaves using BFS are " << numEnclavesUsingBFS(grid)<<endl;
    cout<<"Number of Enclaves using  striver BFS are " << numEnclavesBFS_Striver(grid)<<endl;


return 0;
}