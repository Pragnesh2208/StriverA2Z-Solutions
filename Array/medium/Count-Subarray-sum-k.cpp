/*
Optimal Solution 
TIme Complexity = O(NLogN)
Space Complexity = O(N)
*/
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<long long, int> hashMap;
        long long sum = 0 ;
        int count = 0 , n = nums.size();
        for(int i = 0 ; i < n ;i++) {
            sum += nums[i];
            if(sum == k) count++;
            if(hashMap.find(sum - k ) != hashMap.end()) 
            {count += hashMap[sum - k];}
          
            hashMap[sum]++;
        }
        return count;  
    }
};