/*
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size() , m = goal.size();
        if(n != m ) return false;
        int i = 0 , j = 0;
        s += s;
        n = s.size();

        while(i < n && j < m) {
            if(s[i] == goal[j]) {
                i++;
                j++;
            } else {
                if(s[i] == goal[0]) j = 1;
                else j = 0;
                i++;
            }
        }

        return j == m;
    }
};