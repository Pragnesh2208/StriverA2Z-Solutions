/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int left = 1 , right = nums.size() - 2;
      int index = -1;
      if(nums.size() == 1) return 0;
      if(nums[0] > nums[1]) return 0;
      if(nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
  
      while(left <= right){
        int mid = left + (right - left) / 2;
        if(nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
          index = mid;
          break;
        } else if(nums[mid] > nums[mid + 1]) {
            right = mid - 1;
        } else left = mid + 1;
      }
      return index;
    }
};