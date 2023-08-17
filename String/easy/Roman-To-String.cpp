/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
public:
    int romanToInt(string s) {
        int n = s.size();
        int prev = 0 , total = 0;
        unordered_map<char , int>maping;
        maping['I'] = 1;
        maping['V'] = 5;
        maping['X'] = 10;
        maping['L'] = 50;
        maping['C'] = 100;
        maping['D'] = 500;
        maping['M'] = 1000;

        for(int i =  n - 1 ; i >= 0 ; i-- ){
            if( maping[s[i]] < prev) total -= maping[s[i]];
            else total += maping[s[i]];
            prev = maping[s[i]];
        }
        return total;
    }
};