#include <bits/stdc++.h>
bool check(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first == p2.first || p1.first == p2.second || p1.second == p2.first || p1.second == p2.second;
}
string fourSum(vector<int> arr, int target, int n)
{
    // Write your code here.
    unordered_map<int, pair<int, int>> m;
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            m[arr[i] + arr[j]] = {i, j};
        }
    }

    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int sum = target - (arr[i] + arr[j]);
            if (m.find(sum) != m.end() and !check(m[sum], {i, j}))
            {
                return "Yes";
            }
        }
    }
    return "No";
}
