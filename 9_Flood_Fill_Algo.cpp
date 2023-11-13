#include<bits/stdc++.h>
using namespace std;


void printMatrix(vector<vector<int>>&mat){
    int n = mat.size() , m = mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
void floodFill(int i , int j , vector<vector<int>>&ans ,vector<vector<bool>>&vis, int intialcolor , int newColor){
    ans[i][j] = newColor;
    vis[i][j]=true;
    int n = ans.size();
    int m = ans[0].size();
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    for(int k=0;k<4;k++){
            int p = i + dx[k];
            int q = j + dy[k];
            if(p>=0 and p<n and q>=0 and q<m and vis[p][q]==false and ans[p][q]==intialcolor){
                floodFill(p,q,ans,vis,intialcolor,newColor);
            }
        }
    

}

void floodFill_DFS(int i , int j  ,vector<vector<int>>&ans ,vector<vector<int>>&mat, int intialcolor , int newColor ){
    ans[i][j] = newColor;
    int n = ans.size();
    int m = ans[0].size();
    int dx[] = {-1,1,0,0};
    int dy[] = {0,0,-1,1};
    for(int k=0;k<4;k++){
        int p = i + dx[k];
            int q = j + dy[k];
            if(p>=0 and p<n and q>=0 and q<m and ans[p][q]!=newColor and mat[p][q]==intialcolor){
                floodFill_DFS(p,q,ans,mat,intialcolor,newColor);
            }
    }
}

int main(){

vector<vector<int>>mat={{1,1,1},
                        {2,2,0},
                        {2,2,2}};

int sr = 2 , sc=0;
vector<vector<int>> ans = mat;
vector<vector<bool>>vis(3,vector<bool>(3,false));
int intialColor = 2 , newColor = 3;

// floodFill(sr,sc,ans,vis,intialColor ,newColor);
floodFill_DFS(sr,sc,ans,mat,intialColor ,newColor);
printMatrix(ans);
return 0;
}

/*
T.C = O(N x M x 4)
S.C = O(N X M ) + O(N x M);
*/