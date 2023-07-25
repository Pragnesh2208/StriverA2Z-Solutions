/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int left = 0 , right  = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(arr[mid] < arr[right]) {
                right = mid;
            }
            else {
                left = mid + 1;
            }
        }
        return arr[right];
    }
};