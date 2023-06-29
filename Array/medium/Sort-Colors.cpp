/*
Time Complexity O(N)
Space Complexity O(1)
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
     int start = 0 , end= n - 1;
     for(int i = 0 ; i <= end ; i++) {
         if(nums[i] == 0 ) {
             swap(nums[i] , nums[start++]);
         } else if(nums[i] == 2) 
         swap(nums[i--] , nums[end--]); 
     }
    }
};