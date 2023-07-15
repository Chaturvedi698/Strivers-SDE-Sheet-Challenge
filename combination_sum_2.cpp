 #include<bits/stdc++.h>
 void solve(int index,int &n,vector<int>&arr,vector<vector<int>>&ans,vector<int>temp,int &k,int sum){
	if(sum==k)
	ans.push_back(temp);

	 for(int i = index; i<n; i++){
     if(index!=i and arr[i]==arr[i-1])
     continue;

     temp.push_back(arr[i]);
	 sum +=arr[i];
     solve(i+1,n,arr,ans,temp,k,sum);
     temp.pop_back();
	 sum -=arr[i];
   }
 }
vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	// Write your code here.
	vector<vector<int>>ans;
	vector<int>temp;
	sort(arr.begin(),arr.end());
	solve(0,n,arr,ans,temp,target,0);
	return ans;
}
