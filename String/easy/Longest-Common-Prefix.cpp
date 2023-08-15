/*
Time Complexity = O(M*N)
Space Complexity = O(1)
*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0) return "";

        string ans = strs[0];

        for(int i = 1 ; i < n ; i++) {
            int l1 = strs[i].size();
            int l2 = ans.size();
            int j = 0;
            string temp ="";
            while(j < l1 && j < l2) {
                if(strs[i][j] == ans[j]) temp+= ans[j++];
                else break;

            }
            ans = temp;
        }

        return ans;
    }
};