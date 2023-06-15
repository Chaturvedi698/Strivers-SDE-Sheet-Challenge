#include <bits/stdc++.h>
int uniqueSubstrings(string input)
{
    // Write your code here
    int ans = INT_MIN;
    int left = 0, right = 0;
    unordered_map<char, int> m;

    int n = input.size();
    while (right < n)
    {
        m[input[right]]++;
        if (m.size() == right - left + 1)
        {
            ans = max(ans, right - left + 1);
        }
        else if (m.size() < right - left + 1)
        {
            while (m.size() < right - left + 1)
            {
                m[input[left]]--;
                if (m[input[left]] == 0)
                {
                    m.erase(input[left]);
                }
                left++;
            }
        }
        right++;
    }
    return ans;
}
