/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	int startIndex = -1 , endIndex = -1;
	int low = 0 , high  =  n - 1;
	while(low <= high) {
		int mid = low + (high - low) / 2;
		if(arr[mid] < x) {
			low = mid + 1;
		} else if(arr[mid] > x) {
			high = mid - 1;
		} else {
			startIndex = mid;
			high = mid - 1;
		}
	}

	low = 0 , high = n  - 1;
	while(low <= high) {
		int mid = low + ( high - low) / 2;
		if(arr[mid] > x) {
			high = mid - 1;
		} else if(arr[mid] < x) {
			low = mid + 1;
		} else {
			endIndex = mid; 
			low = mid + 1;
		}
	}
	return startIndex == - 1 ? 0 : endIndex - startIndex + 1;
}
