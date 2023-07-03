class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxElement = 0;
        int n = prices.size();
      
        int ans = 0;
        for(int i = n - 1;  i >= 0 ; i--) {
          
            int maxEle =  maxElement - prices[i];
            ans = max(maxEle , ans);
            maxElement = max(maxElement , prices[i]);
        }
    return ans;
    }
};