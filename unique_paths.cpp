//Approach 1st using dp
#include <bits/stdc++.h>
// vector<vector<int>>di;
int findpath(vector<vector<int>> &di, int i, int j, int &m, int &n)
{
    if (i == m - 1 and j == n - 1)
    {
        return 1;
    }
    if (i >= m or j >= n)
    {
        return 0;
    }
    if (di[i][j] != -1)
    {
        return di[i][j];
    }
    int right = findpath(di, i, j + 1, m, n);
    int down = findpath(di, i + 1, j, m, n);
    return di[i][j] = right + down;
}
int uniquePaths(int m, int n)
{
    // Write your code here.
    vector<vector<int>> di(m + 1, vector<int>(n + 1, -1));
    return findpath(di, 0, 0, m, n);
}


// Approach 2nd

#include <bits/stdc++.h>
int uniquePaths(int m, int n)
{
    // Write your code here.
    int N = m + n - 2;
    int R = m - 1;
    double result = 1;
    for (int i = 1; i <= R; i++)
    {
        result = result * (N - R + i) / i;
    }
    return (int)result;
}