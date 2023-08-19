/*
Time Complexity = O(N)
Space Complexity = O(1)
*/
long long countLessThan(int k , string s) {
    int n = s.size();
    long long cnt = 0 , ans = 0 ;
    vector<int> bucket(26 , 0);
    int i = 0;
    int j = 0;
    long long uniq = 0;
     while(i < n ) {
        if(bucket[s[i] -'a'] == 0) {
            uniq++;
        }

        while(uniq > k) {
            cnt--;
            if(bucket[s[j] -'a'] == 1) uniq--;
            bucket[s[j++] - 'a']--;
        }

            bucket[s[i]-'a']++;
            cnt++;
            if(uniq <= k ) {
                ans += cnt;
            }

        i++;
    }
    return ans;
}
int countSubStrings(string s, int k) 
{
    // Write your code here.
   return countLessThan(k , s)- countLessThan(k - 1  , s);
}
