/*
Time Complexity = O(N)
Space Complexity = O(N)
*/

class Solution {
   
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int>ans;
        int start = 0 , end = nums.size() - 1;
        while(start < end) {
            int sum = nums[start] + nums[end];
            if(sum > target) end--;
            else if(sum < target) start++;
            else {
                ans.push_back(start);
                ans.push_back(end);
                break;
            }
        }
        return ans;
    }
};