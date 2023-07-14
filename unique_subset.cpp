#include <bits/stdc++.h> 
   map<vector<int>,int>m;
 void solve(int index,int &n,vector<int>&arr,vector<vector<int>>&ans,vector<int>temp){
	ans.push_back(temp);

	 for(int i = index; i<n; i++){
     if(index!=i and arr[i]==arr[i-1])
     continue;

     temp.push_back(arr[i]);
     solve(i+1,n,arr,ans,temp);
     temp.pop_back();
   }
 }
vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
  m.clear();
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    sort(arr.begin(),arr.end());
    solve(0,n,arr,ans,temp);
    // vector<vector<int>>curr = {sum.begin(),sum.end()};
    return ans;
}