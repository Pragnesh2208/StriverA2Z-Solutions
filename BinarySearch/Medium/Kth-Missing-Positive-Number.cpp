/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int cnt= 0 ;
        int n = arr.size();
        int left = 0 , right = n - 1;
        
        while(left <= right){
         
            int mid = left + (right - left) / 2;
            int diff = (arr[mid] - (mid + 1));

            if(diff >= k ) {
                right = mid - 1;
            } else left = mid + 1;
        }

        return k + right + 1;

    }
};