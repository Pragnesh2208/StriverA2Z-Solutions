/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	int floor = -1 , ceil = INT_MAX;
	for(int i = 0 ; i < n ; i++) {
		if(arr[i] <= x) {
			floor = max(floor , arr[i]);
		}
		if(arr[i] >= x) {
			ceil = min(ceil , arr[i]);
		}
	}
	ceil = ceil == INT_MAX ? -1 : ceil;
	return {floor , ceil};
}
