#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int el1 = -1, el2 = -1, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (el1 == arr[i])
            cnt1++;
        else if (el2 == arr[i])
        {
            cnt2++;
        }
        else if (cnt1 == 0)
        {
            el1 = arr[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            el2 = arr[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }

    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el1)
            cnt1++;
        else if (arr[i] == el2)
            cnt2++;
    }
    vector<int> ans;
    if (cnt1 > n / 3)
        ans.push_back(el1);
    if (cnt2 > n / 3)
        ans.push_back(el2);
    return ans;
}