/*
Time Complexity = O(Log(10^9) * NLogM)
Space Complexity = O(1)
*/
bool countGood(int midNumber ,  vector<vector<int> > &A , int n , int m) {
    int count = 0;
    for(int i = 0 ; i < n ; i++) {
        int left = -1 , right = m ;
        
        while(right  > left + 1) {
            int mid = left + (right - left) / 2;
            if(A[i][mid] <= midNumber) {
                left = mid ;
            }  else right = mid;
        }
        left = left == m ? 0 : left + 1;
        count += left;
    }
    
    return count > (n * m) / 2 ;
}

int Solution::findMedian(vector<vector<int> > &A) {
    int n11 = A.size() , n22 = A[0].size();
    int left = 0 , right = 1e9  + 1;
    while(right  > left + 1) {
        int mid = left + (right - left) / 2;
        if(countGood(mid , A , n11 , n22)) right = mid;
        else left = mid;
    }
    return right;
}
