#include<bits/stdc++.h>
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>>p;
    for(int i = 0; i<start.size(); i++){
        p.push_back({finish[i],start[i]});
    }
    sort(p.begin(),p.end());
    int activites = 1;
    int end = p[0].first;
    for(int i =1; i<start.size(); i++){
        if(end<=p[i].second){
            activites++;
            end = p[i].first;
        }
    }
    return activites;
}