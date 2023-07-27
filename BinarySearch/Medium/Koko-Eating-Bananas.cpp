/*
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left  = 1  , right = INT_MIN ;
        int n = piles.size();
        for(int i = 0 ; i < n ; i++) {
            right = max(right , piles[i]);
        }

        int ans = -1;

        while(left <= right) {
            int mid = left+ (right - left)  / 2;
            long long temp = 0;
            for(int i = 0 ; i < n ; i++) {
                temp += piles[i] / mid;
                if(piles[i] % mid != 0) temp++;

            }
            if(temp <= h) {
                ans = mid;
                right = mid - 1;
            }
           
             else left = mid + 1;
        }
        return ans;
    }
};