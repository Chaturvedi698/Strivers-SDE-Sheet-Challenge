#include <bits/stdc++.h>

using namespace std;
void solve(int col,int &n,vector<vector<int>>&arr,vector<vector<int>>&ans,vector<int>&left,vector<int>&upperdia,vector<int>&lowerdia){
    if(col==n){
     vector<int>temp;
       for(int i=0; i<n; i++)

  {

        for(int j=0; j<n; j++)

      {

            temp.push_back(arr[i][j]);

        }

    }

    ans.push_back(temp);
        return;
    }
    for(int row = 0;row<n; row++){
        if(left[row]==0 and upperdia[n-1 + col -row]==0 and lowerdia[row+col]==0){
            left[row]=1;
            lowerdia[row+col]=1;
            upperdia[n-1+col-row]=1;
            arr[row][col] = 1;
            solve(col+1,n,arr,ans,left,upperdia,lowerdia);
              left[row]=0;
              arr[row][col] = 0;
            lowerdia[row+col]=0;
            upperdia[n-1+col-row]=0;
        }
    }
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>arr(n,vector<int>(n,0));
    vector<vector<int>>ans;
    if(n>1 &&n<4)return ans;
    vector<int>left(n,0),upperdia(2*n-1,0),lowerdia(2*n-1,0);
    solve(0,n,arr,ans,left,upperdia,lowerdia);
    return ans;
}