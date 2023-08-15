/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
    private : 
    void reverseStr(string &str) {
        int left = 0 , right = str.size() - 1;
        while(left < right) {
            swap(str[left++] , str[right--]);
        }
    }

public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.size();
        reverseStr(s);
        string temp = "";
        for(int i = 0; i <  n ; i++) {
            if(s[i] != ' ') temp+=s[i];
            else if(temp != ""){
                reverseStr(temp);
                if(ans != "") ans += ' ';
                ans+=temp;
                temp ="";
            }
        }
        if(temp != "") {
            if(ans != "") ans += ' ';
            reverseStr(temp);
            ans += temp;
            }
        return ans;
    }
};