/*
Time Complexity = O(LogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int insertIndex = nums.size();
        int low = 0 , high = insertIndex -1;
        while(low <= high) {
            int mid = low + (high - low)  / 2;
            if(nums[mid] >= target) {
                insertIndex = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }  
        return insertIndex; 
    }
};