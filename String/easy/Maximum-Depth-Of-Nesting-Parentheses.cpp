/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    int maxDepth(string s) {
        int cnt = 0;
        int ans = 0;
        int n = s.size();

        for(int i = 0 ; i < n ; i++) {
            if(s[i] =='(') {
                cnt++;
                ans = max(ans , cnt);
            } else if(s[i] == ')') cnt--;

        }
        return ans;
    }
};