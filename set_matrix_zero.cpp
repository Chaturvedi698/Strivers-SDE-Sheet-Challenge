// 1st approach - with using extra space as queue for storing row and column to set them zero later

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        for (int k = 0; k < m; k++)
        {
            matrix[i][k] = 0;
        }
        for (int s = 0; s < n; s++)
        {
            matrix[s][j] = 0;
        }
    }
}

// 2nd Approach without using extra space - In this approach we first traverse whole matrix and set 0 value to -1 then after again traverse matrix and set -1 value to 0 .

#include <bits/stdc++.h>

void setZeros(vector<vector<int>> &matrix)
{
    // Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][j] = -1;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == -1)
            {
                matrix[i][j] = 0;

                for (int k = 0; k < m; k++)
                {
                    if (matrix[i][k] == -1)
                        continue;
                    matrix[i][k] = 0;
                }

                for (int s = 0; s < n; s++)
                {
                    if (matrix[s][j] == -1)
                        continue;
                    matrix[s][j] = 0;
                }
            }
        }
    }
}