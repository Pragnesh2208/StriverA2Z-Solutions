/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
int upperBound(vector<int> &arr, int x, int n){
	// Write your code here.	
	int upperBound = n ;
	int low = 0 , high = n -1;
	while(low <= high) {
		int mid = low + (high - low);
		if(arr[mid] > x) {
			upperBound = mid;
			high = mid - 1;
		} else if(arr[mid] <= x) {
			low = mid + 1;
		}
	}
	return upperBound;

}