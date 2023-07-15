void solve(int index, vector<int>&arr,vector<vector<int>>&ans,vector<int>temp,int n, int &k,int sum){
    if(index>=n){
        if(sum==k){
            ans.push_back(temp);
        }
        return;
    }

    temp.push_back(arr[index]);
    sum += arr[index];
    solve(index+1,arr,ans,temp,n,k,sum);
    temp.pop_back();
    sum -= arr[index];
    solve(index+1,arr,ans,temp,n,k,sum);
}
vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>temp;
    solve(0,arr,ans,temp,n,k,0);
    return ans;
}