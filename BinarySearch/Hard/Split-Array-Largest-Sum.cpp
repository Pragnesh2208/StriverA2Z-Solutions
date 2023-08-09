/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {

    private : 
    bool isGood(int mid , vector<int>&nums , int &k) {
        int task = 1;
        long long sum = 0 ;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++) {
            if(nums[i]  > mid ) return false;
            else if(nums[i] + sum <= mid) {
                sum+= nums[i];
            } else {
                sum = nums[i] ;
                task++;
            }
        }

        return task <= k;
    }

public:
    int splitArray(vector<int>& nums, int k) {

        int n = nums.size();

        int left = -1 , right = 1;
        long long sum = 0 ;

        for(int i = 0 ; i < n ; i++) {
            sum += nums[i];
        } 
        
        right = sum;

        while(right > left + 1) {
            int mid = left + ( right - left) / 2;
            if(isGood(mid , nums , k)) right = mid;
            else left = mid;
        }

        return right;
    }
};