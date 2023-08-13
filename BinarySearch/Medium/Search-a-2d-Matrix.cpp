/*
Approach 1 
Time Complexity = O(Log(N*M))
Space Complexity = O(1)
*/
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0 , high = m*n - 1;
        bool flag = false;
        while(low <= high) {
            int mid = (high + low) / 2;
            int row = mid / n  , col = mid % (n );
            
            if( matrix[row][col] == target ) {
                flag = true;
                break;
            }
            if( matrix[row][col] > target ) {
                high = mid - 1;
            }
            else low = mid + 1;

        }
        return flag;
    }
};

/*
Appraoch 2 
Time Complexity = O(Log(M) + Log(N))
Space Complexity = O(1)
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int left = 0 , right = matrix.size() - 1;
        while(left <= right) {
            int row = left + (right - left) / 2;
            int colLimit = matrix[row].size() - 1;
            if(matrix[row][0] <= target && matrix[row][colLimit] >= target) {
             
                int left1 =  0 , right1 = matrix[row].size() - 1;
                while(left1 <= right1) {
                int col = left1 + (right1 - left1) / 2;
                if(matrix[row][col] == target ) {
                    return true;
                } else if(matrix[row][col] < target) {
                    left1 = col + 1; 
                } else right1 = col - 1;
            }
            return false;
            } else if(matrix[row][0] > target) {
                right = row - 1;
            } else left = row + 1;
        }
        return false;
    }
};