#include<bits/stdc++.h>
using namespace std;


// we will use BFS here bcz we have multiple source from where rotten of oranges will start simultaneoulsy and we have to rotten it level wise 
// we will have a queue<pair<pair<int,int>,int>> to store the time at which the oranges will start rottening 

void printMatrix(vector<vector<int>>&mat){
    int n = mat.size() , m = mat[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

void bfs(vector<vector<int>>&oranges ,int &time ){
    queue<pair<pair<int,int>,int>>q;
    int n = oranges.size() , m = oranges[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(oranges[i][j]==2) q.push({{i,j},0});
        }
    }
    int dx[]={-1,1,0,0};
    int dy[] = {0,0,-1,1};
    while(!q.empty()){
        auto node = q.front();
        int row = node.first.first;
        int col = node.first.second;
        int t = node.second;
        time = max(time , t);
        q.pop();
        for(int k=0;k<4;k++){
            int nrow = row + dx[k];
            int ncol = col + dy[k];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and oranges[nrow][ncol]==1){
                oranges[nrow][ncol]=2;
                q.push({{nrow,ncol} , t+1});
            }
        }

    }

}

int main(){
    vector<vector<int>>oranges = {{0,1,2},
                                  {0,1,1},
                                  {2,1,1}};

int time = INT_MIN;
bfs(oranges,time);
printMatrix(oranges);
cout<<time<<endl;
return 0;
}
/*
T.C = O(N x M)
S.C = O(N x M)

*/