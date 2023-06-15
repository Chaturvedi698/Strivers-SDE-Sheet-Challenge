#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    //    Write your code here.
    int cnt = 0;
    int xr = 0;
    map<int, int> m;
    m[xr]++;
    for (int i = 0; i < arr.size(); i++)
    {
        xr = xr ^ arr[i];
        int k = xr ^ x;
        cnt += m[k];
        m[xr]++;
    }
    return cnt;
}