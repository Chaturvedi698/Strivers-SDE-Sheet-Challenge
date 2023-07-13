#include <bits/stdc++.h> 
bool comparator(vector<int>a,vector<int>b){
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(),jobs.end(),comparator);
    int max_dedline = 0;
    int n = jobs.size();
    for(int i = 0; i<n; i++){
        max_dedline = max(max_dedline,jobs[i][0]);
    }
    vector<int>slots(max_dedline+1,-1);
    int ans = 0;
    for(int i = 0; i<n; i++){
        int profit = jobs[i][1];
        int dedline = jobs[i][0]-1;
        while(dedline>=0){
            if(slots[dedline]==-1){
                slots[dedline] = i;
                ans += profit;
                break;
            }
            dedline--;
        }
    }
    return ans;
}
