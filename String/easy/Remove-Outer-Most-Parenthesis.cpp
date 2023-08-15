/*
Time Complexiy = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans = "";
        int length = s.size();
        int cnt = 0;
        bool outer = false;

        for(int i = 0 ; i < length ; i++) {
            if(s[i]=='(' && !outer ) {  
                outer = true;
                cnt++;
            }
            else if(s[i] == '(') {
                cnt++;
                ans += '(';
            }
            else if(s[i] ==')') {
                if(cnt > 1) ans +=  ')';
                else if(cnt == 1 && !oaauter) ans += ')';
                cnt--;
                }
            if(cnt == 0 ) {
                outer = false;
            }
        }
        return ans;   
    }
};