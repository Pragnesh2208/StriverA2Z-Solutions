/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    int maxProduct(vector<int>& nums) {
       int prefix = 1 , suffix = 1 , maxProduct = INT_MIN;
       int n = nums.size();
       for(int i = 0 ; i < n ; i++) {
           if(prefix == 0) prefix = 1;
           if(suffix == 0) suffix = 1;
           prefix *= nums[i];
           suffix *= nums[ n - 1 - i];
           maxProduct = max(maxProduct , max(prefix , suffix));
       }
       return maxProduct;
    }
};