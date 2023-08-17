/*
Approach 1 Using Sorting
Time Complexity = O(N)
Space Complexity = O(1)
*/
class Solution {
    private:
    static bool cmp(pair<char,int> a , pair<char,int>b) {
        if(a.second > b.second) return true;
        return false;
    }
public:
    string frequencySort(string s) {
        vector<pair<char,int>>freq(256);
        for(int i = 0 ; i < 256 ; i++) freq[i].first = (char)i;
        int n = s.size();
        for(int i = 0 ; i < n ; i++) {
            freq[(int)s[i]].second++;
        }

        sort(freq.begin() , freq.end() , cmp);
        string ans = "";
        for(int i = 0 ; i < 256 && freq[i].second > 0 ; i++) {
            while(freq[i].second-- > 0)
            ans += freq[i].first;
        }

        return ans;
    }
};

/*
Approach 2 Without Sorting
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
    private:
    static bool cmp(pair<char,int> a , pair<char,int>b) {
        if(a.second > b.second) return true;
        return false;
    }
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans = "";
        vector<pair<char,int>>freq(256);
        vector<vector<char>>bucket(n + 1 , vector<char>());
        
        for(int i = 0 ; i < 256 ; i++) freq[i].first = (char)i;

        for(int i = 0 ; i < n ; i++) {
            freq[(int)s[i]].second++;
        }

        for(int i = 0 ; i < 256 ; i++) {
            bucket[freq[i].second].push_back(freq[i].first);
        }

        for(int i = n ; i > 0 ; i--) {
            if(bucket[i].size())
            for(int j = 0 ; j < bucket[i].size() ; j++) {
                for(int k = 0 ; k < i ; k++) ans += bucket[i][j];
            }
        }
        return ans;
    }
};