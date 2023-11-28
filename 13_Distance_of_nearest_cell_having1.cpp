#include<bits/stdc++.h>
using namespace std;



void printMatrix(vector<vector<int>>&matrix){
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[0].size();j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

vector<vector<int>> nearest(vector<vector<int>>&grid){
    int n = grid.size() , m = grid[0].size();
    vector<vector<int>> vis(n , vector<int>(m,0));
    vector<vector<int>> dist( n , vector<int>(m,0));
    queue<pair<pair<int,int>,int>>q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                q.push({{i,j} , 0});
                vis[i][j]=1;
            }
            else{
                vis[i][j]=0;
            }
        }
    }
    int dx[]={-1,1,0,0};
    int dy[]={0,0,-1,1};
    while(!q.empty()){
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for(int k=0;k<4;k++){
            int nrow =  row + dx[k];
            int ncol = col + dy[k];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and vis[nrow][ncol]==0){
                vis[nrow][ncol]=1;
                q.push({{nrow,ncol} , steps+1});
            }
        }
    }
    return dist;

}
void bfs(vector<vector<int>>&matrix , vector<vector<bool>>&vis , vector<vector<int>>&ans){
    int n = matrix.size() , m = matrix[0].size();
    queue<vector<int>>q; // vector of size 3 -> {i,j,dist};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
            q.push({i,j,0});
            ans[i][j]=0;
        }
    }
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    while(!q.empty()){
        auto front = q.front();
        q.pop();
        int i = front[0] , j = front[1] , dist = front[2];
        ans[i][j] = dist;
        vis[i][j] = true;
        for(int k=0;k<4;k++){
            int nx = i + dx[k] , ny = j + dy[k];
            if(nx>=0 and nx<n and ny>=0 and ny<m and !vis[nx][ny] and matrix[nx][ny]==0)
                q.push({nx,ny,dist+1});
                
        }
    }
    }
}


int main(){
    int n = 3 , m = 3;
    vector<vector<int>>matrix={{0,0,0},
                                {0,1,0},
                                {1,0,1}};
    vector<vector<int>>ans(n,vector<int>(m,0));
    vector<vector<bool>>vis(n,vector<bool>(m,false));
    bfs(matrix ,vis , ans );
    cout<<"original matrix"<<endl;
    printMatrix(matrix);
    cout<<"Distance Matrix"<<endl;
    printMatrix(ans);

return 0;
}