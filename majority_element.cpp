#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n)
{
    // Write your code here.
    int cnt = 0;
    int element = 0;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            element = arr[i];
            cnt++;
        }
        else
        {
            if (element == arr[i])
                cnt++;
            else
                cnt--;
        }
    }

    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (element == arr[i])
            cnt++;
    }
    return (cnt > n / 2) ? element : -1;
}