/*
Time Complexity = O(N)
Space Complexity = O(1)
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
       int count = 0 , ans = -1 , n = nums.size();
       for(int i = 0 ; i < n ; i++) {
           if( count == 0 | ans == nums[i]) {
               count++;
               ans = nums[i];
           } else {
               count--;
           }
       }
       return ans;
    }
};