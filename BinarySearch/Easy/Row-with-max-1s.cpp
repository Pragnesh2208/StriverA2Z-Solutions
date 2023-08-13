/*
Time Complexity = O(NLogM)
Space Complexity = O(1)
*/

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.
    int ans , maxCnt = 0;
    for(int i = 0 ; i < n ; i++) {
        int left = -1 , right = matrix[i].size();

        while(right > left + 1) {
            int mid = left + (right - left) / 2;
            if(matrix[i][mid] == 1) {
                right = mid;
            } else left =  mid;
        }
         if((m - right) > maxCnt) {
             maxCnt = (m - right);
             ans = i;K
         }
    }
    return ans;
}