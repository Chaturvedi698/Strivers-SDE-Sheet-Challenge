#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{

    sort(arr.begin(), arr.end());

    vector<vector<int>> pairs;

    int j = 0;

    for (int i = 1; i < arr.size(); i++)

    {

        int sum = arr[j] + arr[i];

        if (sum == s)

        {

            vector<int> temp;

            temp.push_back(arr[j]);

            temp.push_back(arr[i]);

            pairs.push_back(temp);
        }

        if ((sum > s) || ((i == arr.size() - 1) && (j < arr.size())))

        {

            j++;

            i = j;
        }
    }

    return pairs;
}