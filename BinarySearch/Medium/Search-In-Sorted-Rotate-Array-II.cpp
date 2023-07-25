/*
Time Complexity = O(N) & Theta of (LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        bool flag = false;
        int n = nums.size();
        int left = 0 , right = n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target) {
                flag = true;
                break;
            } else if(nums[right] == nums[left]) {
                if(nums[left] == target) {
                    flag = true;
                    break;
                }
                left++;
                right--;
            } else if(nums[mid] <= nums[right]) {
                if(target > nums[mid] && target <= nums[right] ) left = mid + 1;
                else right = mid - 1;
            } else {
                if(target < nums[mid] && target >= nums[left]) right = mid - 1;
                else left = mid + 1;
            }
        }
        return flag;
    }
};