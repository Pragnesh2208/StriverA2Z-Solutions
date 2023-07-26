/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n = arr.size();
        if(n == 1) return arr[0];
        if(arr[0] != arr[1] )return arr[0];
        if(arr[n - 1] != arr[n - 2]) return arr[n - 1];
        int index = -1;
        int left = 1 , right  = n  - 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(mid % 2 != 0) {
                if(arr[mid] == arr[mid - 1]) left = mid + 1;
                else if(arr[mid] == arr[mid + 1]) right = mid - 1;
                else {
                index = mid;
                break;
                }
            }
            else {
                if(arr[mid] == arr[mid - 1]) right = mid - 1;
                else if(arr[mid] == arr[mid + 1]) left = mid  + 1;
                else {
                    index = mid;
                    break;
                }
            }
           
        }
        return arr[index];
    }
};