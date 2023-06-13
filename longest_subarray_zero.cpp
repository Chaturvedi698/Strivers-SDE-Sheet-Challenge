#include <bits/stdc++.h>

int LongestSubsetWithZeroSum(vector<int> arr)
{

    // Write your code
    int n = arr.size();
    int llength = 0;
    int sum = 0;
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            llength = i + 1;
        }
        else
        {
            if (m.find(sum) != m.end())
            {
                llength = max(llength, i - m[sum]);
            }
            else
            {
                m[sum] = i;
            }
        }
    }
    return llength;
}