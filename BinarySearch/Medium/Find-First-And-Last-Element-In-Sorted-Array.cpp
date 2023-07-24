/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
     int startIndex = -1 , endIndex = -1;
     int n = nums.size();
     int low = 0 , high = n - 1;
     while(low <= high) {
         int mid = low + (high - low) / 2;
         if(nums[mid] == target) {
             startIndex = mid;
             high = mid - 1;
         } else if(nums[mid]  > target) high = mid - 1; 
         else low = mid + 1;
     } 
     low = 0 , high = n  - 1;
     while(low <= high) {
         int mid = low + (high - low) / 2;
         if(nums[mid] == target) {
             endIndex = mid;
             low = mid + 1;
         } else if(nums[mid] < target) {
             low = mid + 1;
         } else high = mid - 1;
     }

     return{startIndex, endIndex};
    }
};