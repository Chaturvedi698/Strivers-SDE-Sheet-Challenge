long long getTrappedWater(long long* arr, int n) {
    // Write your code here.
    int leftmax = 0, rightmax = 0, left = 0, right = n-1;
    long long ans = 0;
    while(left<right){
        if(arr[left]<=arr[right]){
          if (arr[left] > leftmax) {
            leftmax = arr[left];
          }
          else{
              ans  += leftmax - arr[left];
          }
            left++;
        }
        else{
            if(arr[right]>rightmax){
                rightmax = arr[right];
            }
            else{
                ans += rightmax - arr[right];
            }
            right--;
        }
    }
    return ans;
}