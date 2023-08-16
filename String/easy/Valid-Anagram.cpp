/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>bucket(26 ,0);

        int n = s.size() , m = t.size();
        bool ans = true;
        if(n != m) return false;

        for(int i = 0 ; i < n ;i++) {
            bucket[s[i] - 'a']++;
            bucket[t[i] - 'a']--;
        }

        for(int cnt : bucket) if(cnt !=0 ) {
            ans = false;
            break;
        }

        return ans;
    }
};