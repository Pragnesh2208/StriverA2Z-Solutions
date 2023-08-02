/*
Time Complexity = O(NLogn)
Space Complexity = O(1)
*/
class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n = nums.size();
        int left = 1 , right = INT_MIN , ans = -1;
        for(int i = 0 ; i < n; i++) right = max(right , nums[i]);

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int sum = 0 ; 
            for(int i = 0 ; i < n ; i++) {
                int temp = nums[i] / mid ;
                if(nums[i] % mid != 0) temp++;
                sum += temp;
            }

            if(sum <= threshold) {
                ans = mid;
                right = mid - 1;
            } else left = mid + 1;
        }
        return ans;
    }
};