/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
int findKRotation(vector<int> &arr){
    // Write your code here.    
    int n = arr.size();
    int left = 0 , right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
       if(arr[mid] < arr[right]) {
           right = mid ;
       } else left = mid + 1;
    }

    return right;
}