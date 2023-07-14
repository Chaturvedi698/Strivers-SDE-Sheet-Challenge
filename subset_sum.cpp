 void solve(int index,int &n,vector<int>&num,vector<int>&ans,int sum){
	 if(index>=n){
		 ans.push_back(sum);
		 return;
	 }

	 //take
	 solve(index+1,n,num,ans,sum+num[index]);
	 //not take
	 solve(index+1,n,num,ans,sum);
 }
vector<int> subsetSum(vector<int> &num){
	// Write your code here.	
	vector<int>ans;
	int n = num.size();
	solve(0,n,num,ans,0);
	sort(ans.begin(),ans.end());
	return ans;
}