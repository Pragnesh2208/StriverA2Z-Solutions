/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
	int index = n;
	int low = 0  , high = n - 1;
	while(low <= high) {
		int mid = low + (high - low) /2;
		if(arr[mid] >= x) {
			index = mid;
			high = mid - 1;
		} else if( arr[mid] < x) {
			low = mid + 1;
		} 
	}
	return index;

}
