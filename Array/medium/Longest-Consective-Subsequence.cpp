/*
Time Complexity O(NLOGN)
Space Complexity O(1)
)*/
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 0 ) return 0;
        sort(nums.begin() , nums.end());
        int ans = 1 , count = 1 , prev = nums[0];

        for(int i = 1 ; i < n ; i++) {
            if(nums[i] != nums[i-1] && nums[i] - prev == 1) {
                count++;
                prev = nums[i];
                ans = max(ans , count); 
            }
            else if(nums[i] != nums[i-1]) {
                count = 1;
                prev = nums[i];}
        }
        return ans;
       
     }
};

/*
Time Complexity  O(N)
Space Complexity O(N)
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
     unordered_set<int>bucket ; 
     int n = nums.size();
     if(n == 0 || n == 1) return n;
     for(int i = 0 ; i < n ; i++) {
         bucket.insert(nums[i]);
     }

    int ans = 1;
     for(int p : bucket)  {
         if(bucket.find(p-1) == bucket.end()) {
             int count = 1;
             int temp = p + 1;
            while(bucket.find(temp) != bucket.end()) {
                count++;
                temp++;
            }
            ans = max(ans , count);
         }
     }
     return ans;
       
     }
};