/*
Time Complexity = O(NLogn)
Space Complexity = O(1)
*/
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int left = INT_MIN , right = 0 , ans = -1;

        for(int i = 0 ; i < n ; i++) {
            left = max(left , weights[i]);
            right += weights[i];
        }

        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cnt = 0 , sum = 0;
            int i = 0;
            while(i < n ) {
                if(sum + weights[i] > mid) {
                    cnt++;
                    sum = 0;
                } else if(sum + weights[i] < mid) {
                    sum += weights[i];
                    i++;
                } else {
                    sum = 0;
                    cnt++;
                    i++;
                }
            }
            if(sum !=0 ) cnt++;
            if(cnt <= days) {
                ans = mid;
                right = mid - 1;
            }  else left = mid + 1;
        }
        return ans;
    }
};