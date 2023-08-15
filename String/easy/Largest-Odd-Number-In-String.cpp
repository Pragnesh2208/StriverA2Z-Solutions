/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "0";
        int n = num.size();
        int lastIndex = -1;
        for(int i = 0  ; i < n ; i++) {
            int temp = num[i] - '0';
            if(temp % 2) lastIndex = i;
        }
        cout<<lastIndex<<endl;
        return lastIndex == -1 ? "" : num.substr(0,lastIndex + 1);
    }
};