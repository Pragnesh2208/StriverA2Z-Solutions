/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0 , right = n  - 1;
        int ans = -1;
        while(left <= right)  {
            int mid = left + (right - left) / 2;
           if(nums[mid] == target) {
               ans = mid;
               break;
           } else if(nums[mid] < nums[right]) {
                if(target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else right = mid - 1;
           }
           else {
               if(target >= nums[left] && target < nums[mid]) right = mid - 1;
               else left = mid + 1;
           }
        }
        return ans;
    }
};