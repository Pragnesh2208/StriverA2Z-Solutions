/*
Time Complexity = O(MLogN)
Space Complexity = O(1)
*/
class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size()  , m = mat[0].size();
        int top = 0 , bottom = n - 1;
        while(top <= bottom) {
            int peakCol = 0;
            int mid = top + ( bottom - top) / 2;
            for(int i = 0 ; i < m ; i++) {
                peakCol = mat[mid][peakCol] < mat[mid][i] ? i : peakCol;
            }
            int topEle = mid == 0 ? -1 : mat[mid - 1][peakCol];
            int bottomEle = mid == n - 1 ? -1 :mat[mid + 1][peakCol];

            if(mat[mid][peakCol] > topEle && mat[mid][peakCol] > bottomEle) 
                return {mid , peakCol};
            else if(mat[mid][peakCol] < topEle) bottom = mid - 1;
            else top = mid + 1;
        }
        return {-1,-1};
    }
};s