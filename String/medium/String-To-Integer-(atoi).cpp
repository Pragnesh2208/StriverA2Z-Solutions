/*
Time Complexity = O(N)
Space Complexity = O(1)
*/

class Solution {
public:
    int myAtoi(string s) {
        long number = 0;
        int n = s.size();
        bool neg = false;
        int index = 0;

        while(s[index] == ' '){index++;}
        if(s[index] == '-' ) neg = true;
        if(s[index] == '-' || s[index] == '+') index++;

        for(int i = index ; i < n ; i++) {
            int temp = s[i] - '0';
            if(temp >= 0 && temp <= 9) {
                number *= 10;
                number += temp;

                if(!neg && number >= INT_MAX ) return INT_MAX;
                else if(neg && -1* number <= INT_MIN) return INT_MIN;

            } else break;
        } 

        if(neg) number *= -1;
        return (int)number;
    }
};