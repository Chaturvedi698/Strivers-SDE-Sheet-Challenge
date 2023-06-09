bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0;
    int high = m - 1;
    int mid = 0;
    for (int i = 0; i < n; i++)
    {
        low = 0, high = m - 1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (mat[i][mid] == target)
            {
                return true;
            }
            else if (mat[i][mid] > target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
    }
    return false;
}