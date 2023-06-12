#include <bits/stdc++.h>
void check(vector<int> &arr, int low, int mid, int right, int high, int &cnt)
{
    while (low <= mid)
    {

        while (right <= high and arr[low] > 2 * arr[right])
        {
            right++;
        }
        cnt += (right - (mid + 1));
        low++;
    }
}
void merge(vector<int> &arr, int low, int mid, int high, int &cnt)
{

    int left, right;

    left = low;

    right = mid + 1;

    vector<int> temp;

    check(arr, low, mid, right, high, cnt);
    while (left <= mid && right <= high)
    {

        if (arr[left] <= arr[right])
        {

            temp.push_back(arr[left]);

            left++;
        }
        else
        {

            temp.push_back(arr[right]);

            right++;
        }
    }

    while (left <= mid)
    {

        temp.push_back(arr[left]);

        left++;
    }

    while (right <= high)
    {

        temp.push_back(arr[right]);

        right++;
    }

    for (int i = low; i <= high; i++)
    {

        arr[i] = temp[i - low];
    }
}

void merges(vector<int> &arr, int low, int high, int &cnt)
{

    if (low < high)
    {

        int mid = (low + high) / 2;

        merges(arr, low, mid, cnt);

        merges(arr, mid + 1, high, cnt);

        merge(arr, low, mid, high, cnt);
    }
}
int reversePairs(vector<int> &arr, int n)
{
    // Write your code here.
    int cnt = 0;
    merges(arr, 0, n - 1, cnt);
    return cnt;
}