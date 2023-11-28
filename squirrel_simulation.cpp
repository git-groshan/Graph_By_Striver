#include<bits/stdc++.h>
using namespace std;

class solution{
    int distance(vector<int>&a , vector<int>&b){
        return abs(a[0]-b[0]) + abs(a[1]-b[1]);
    }

    int minDistance(int height , int width , vector<int>&tree , vector<int>&squirrel , vector<vector<int>>&nuts){
        int ans = INT_MAX , maxDiff = INT_MIN , total =0;
        for(auto &nut :nuts){
            total+=distance(nut,tree);
            maxDiff = max(maxDiff , distance(nut,tree) - distance(nut,squirrel));
        }

        return 2*total - maxDiff;
    }
};
int main(){

return 0;
}