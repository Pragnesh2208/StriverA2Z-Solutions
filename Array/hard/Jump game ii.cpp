/*
Time Complexity = O(N)
space Complexity = O(1)
*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int farthest = 0 , curr_index = 0 , jump = 0;
        for(int i = 0 ; i < n - 1; i++){
            farthest = max(farthest , i + nums[i]);
            if(i == curr_index) {
                curr_index = farthest;
                jump++;
            }
        }
        return jump;
    }
};a