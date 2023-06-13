#include <bits/stdc++.h>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }

    int ans = INT_MIN;
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        if (s.find(arr[i] - 1) != s.end())
        {
            continue;
        }
        else
        {
            int j = arr[i];
            cnt = 0;
            while (s.find(j) != s.end())
            {
                cnt++;
                j++;
            }
        }
        ans = max(ans, cnt);
    }
    return ans;
}
