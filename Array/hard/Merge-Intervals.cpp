/*
Optimal Solution
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        int n = intervals.size();
        sort(intervals.begin() , intervals.end());
        ans.push_back(intervals[0]);
        for(int i = 1 ; i < n ;i++) {
            int startRange = ans.back()[0];
            int endRange = ans.back()[1];
            if(intervals[i][0] <= endRange) {
                if(intervals[i][1] > endRange)
                ans.back()[1] = intervals[i][1];
            }  else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};