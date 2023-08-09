class Solution {
    private :
    bool isGood(int mid , vector<int>&a , int k) {
        int n = a.size();
        int prev = a[0];
        int cnt = 1;
        for(int i = 1; i < n  ; i++) {
            if(a[i] - prev >= mid) {
                cnt++;
                prev = a[i];
            }
        }

        return cnt >= k;
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size(); 
        int left = 0 , right = 1e9;

        sort(price.begin() , price.end());

        while(right > left + 1) {
            int mid = left + (right - left) / 2;

            if(isGood(mid , price , k)) left = mid;
            else right = mid;
        }

        return left;
    }
};