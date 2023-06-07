#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // Write your code here.

    sort(intervals.begin(), intervals.end());

    int n = intervals.size();
    int i = 1;
    vector<vector<int>> ans;
    int prevrow = 0, prevcol = 0;
    prevrow = intervals[0][0];
    prevcol = intervals[0][1];
    while (i != n)
    {
        int row = intervals[i][0];
        int col = intervals[i][1];

        if (prevcol >= row and prevcol >= col)
        {
            i++;
            continue;
        }
        else if (prevcol >= row)
        {
            // ans.push_back([prevrow,col]);
            prevcol = col;
        }
        else
        {
            ans.push_back({prevrow, prevcol});
            prevrow = row;
            prevcol = col;
        }
        i++;
    }
    ans.push_back({prevrow, prevcol});
    return ans;
}
