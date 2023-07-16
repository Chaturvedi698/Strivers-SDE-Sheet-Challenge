#include <bits/stdc++.h> 
void solve(int index,string &s, vector<string>&ans){
    if(index==s.size()){
        ans.push_back(s);
        return;
    }

    for(int i = index; i<s.size(); i++){
        swap(s[i],s[index]);
        solve(index+1,s,ans);
        swap(s[i],s[index]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string>ans;
    solve(0,s,ans);
    return ans;

}