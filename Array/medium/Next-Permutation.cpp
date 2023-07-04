/*
Time Complexity : O(N)
Space Complexity : O(1)
*/

class Solution {
    private : 
    void reverse(vector<int>&arr , int start , int end) {
        while(start < end) {
            swap(arr[start++] , arr[end--]);
        }
    }
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        if(n == 1) return;
        int end = n - 2;
        int infpoint = -1;
        while(end >= 0) {
            if(nums[end] < nums[end + 1]) {
                infpoint = end;
                break;
            }
          
            end--;
        }

        if(infpoint == - 1) {
           reverse(nums , 0 , n - 1);
        } else {
            int smallest = -1;
            for(int i = n - 1;  i > infpoint ; i-- ) {
                if(nums[i] >nums[infpoint] ) {
                  if(smallest == -1 || nums[smallest] > nums[i]) {
                      smallest = i;
                  } 
                } 
            }
            swap(nums[smallest] , nums[infpoint]);
            reverse(nums , infpoint + 1 , n - 1);
        }

        return ;
    }
};