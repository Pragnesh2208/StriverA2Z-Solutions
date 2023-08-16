/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n != m) return false;

        vector<int>bucketS(256,0), bucketT(256,0);
        for(int index = 0 ;  index < n ; index++) {
            cout<<bucketS[s[index]]<<" "<<bucketT[t[index]]<<endl;
            if(bucketS[s[index]] != bucketT[t[index]]) return false;
            bucketS[s[index]] = index + 1;
            bucketT[t[index]]  = index + 1; 
        }
        
        return true;
    }
};