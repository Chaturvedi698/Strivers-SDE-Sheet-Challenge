
int singleNonDuplicate(vector<int>& arr)
{
	// Write your code here
	int left = 0;
	int right = arr.size()-1;
	while(left<=right){
		int mid=  (left+right)/2;
		if((mid%2==0 and arr[mid]==arr[mid+1]) or( mid%2==1 and arr[mid]==arr[mid-1])){
			left = mid+1;
		}
		else{
			right = mid-1;
		}
	}
		return arr[left];
}