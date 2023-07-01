#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>arr, int n, int K) {
	// Write your code here.
	// vector<vector<int>>ans;
	set<vector<int>>temp;
	sort(arr.begin(),arr.end());
	for(int i = 0; i<n-2; i++){
		int low = i+1, high = n-1;
		while(low <high){
			int sum = arr[i]+arr[low]+arr[high];
			if(sum==K){
				temp.insert({arr[i],arr[low],arr[high]});
				low++;
				high--;
			}
			else if (sum<K){
				low++;
			}
			else {
				high--;
			}
		}
	}
	vector<vector<int>>ans(temp.begin(),temp.end());
	return ans;
}