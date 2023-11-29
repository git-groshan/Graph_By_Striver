#include<bits/stdc++.h>
using namespace std;

/**
 * Approach - start DFS from the corner where O is places marked all O vis which are connected to corner as they can never be converted to X . 
 * Now traverse in vis array and check if which  O is not visited then that can be converted into X cuz it will be surrounded by X
 * 1. Set of O's connected to boundaries O  , it can not be converted in X
*/




void printMatrix(vector<vector<char>>&v){
    int n = v.size() , m = v[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}
void convert_O_in_X(int  i , int j ,int n , int m , vector<vector<char>>mat, vector<vector<bool>>&vis){
    vis[i][j] = true;
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    for(int k=0;k<4;k++){
        int new_x = i + dx[k];
        int new_y = j + dy[k];
        if(new_x>=0 && new_x<n && new_y>=0 && new_y<m && mat[new_x][new_y]=='O' && vis[new_x][new_y]==false){
            convert_O_in_X(new_x , new_y , n , m , mat, vis);
        }
    }
}

int main(){

int n = 5 , m = 4;
/*
vector<vector<char>> mat =  {{'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}};

*/
vector<vector<char>> mat = {{'X', 'X', 'X', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'O', 'O', 'X'}, 
       {'X', 'O', 'X', 'X'}, 
       {'X', 'X', 'O', 'O'}};

vector<vector<bool>>vis(n , vector<bool>(m,false));

cout<<"Printing actual matrix "<<endl;
printMatrix(mat);
// traverse to all the corner and check for O's and do a dfs for it.
// top row
for(int j=0;j<m;j++){
    if(mat[0][j]=='O' and !vis[0][j]) convert_O_in_X(0,j,n,m,mat,vis); 
    if(mat[n-1][j]=='O' and !vis[n-1][j]) convert_O_in_X(n-1,j,n,m,mat,vis); 
}
/*
// bottom row
for(int j=0;j<m;j++){
    if(mat[n-1][j]=='O' and !vis[n-1][j]) convert_O_in_X(n-1,j,n,m,mat,vis); 
}
*/
// first col 
for(int i=0;i<n;i++){
    if(mat[i][0]=='O' and !vis[i][0]) convert_O_in_X(i,0,n , m , mat , vis);
    if(mat[i][m-1]=='O' and !vis[i][m-1]) convert_O_in_X(i,m-1,n , m , mat , vis);
}
/*
// last col

for(int i=0;i<n;i++){
    if(mat[i][m-1]=='O' and !vis[i][m-1]) convert_O_in_X(i,m-1,n , m , mat , vis);
}
*/

// whichever O is not vis will be marked as X
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(mat[i][j]=='O' and !vis[i][j]) mat[i][j]='X';
    }
}
cout<<"Printing updated matrix "<<endl;
printMatrix(mat);

/*
T.C = O(N x M x 4) ~= O(N x M)
*/



return 0;
}