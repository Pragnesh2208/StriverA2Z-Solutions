/*
Using Space Optimization
Time Complexity = O(N ^ 2)
Space Complexity = O(1)
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans (numRows , vector<int>(1, 1) );
        for(int i = 1 ; i < numRows ; i++) {
            for(int j = 1 ; j < i  ; j++) {
                ans[i].push_back (ans[i - 1][j - 1] + ans[i-1][j]);
            }
            ans[i].push_back(1);
        }
        return ans;
    }
};