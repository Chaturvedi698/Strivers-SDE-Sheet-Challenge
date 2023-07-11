int longestSubSeg(vector<int> &arr, int n, int k)
{
    // Write your code here.
    int left = 0, right = 0;
    int cnt = 0, ans = 0;
    while (right < n)
    {
        if (arr[right] == 0)
            cnt++;
        while (cnt > k)
        {
            if (arr[left] == 0)
                cnt--;
            left++;
        }
        ans = max(ans, right - left + 1);
        right++;
    }
    return ans;
}
