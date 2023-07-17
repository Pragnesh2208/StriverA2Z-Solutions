/*
Optimal Solution
Time Complexity = O(NLogN)
Space Complexity = O(N)
*/
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // Your code here
        
        int maxLen = 0 ;
        map<long long,int> hashMap;
        long long sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += A[i];
            if(sum == 0) {
                maxLen = max(maxLen , i + 1);
            }
            
            else if(hashMap.find(sum) != hashMap.end()) {
                maxLen = max( i  - hashMap[sum] , maxLen);
            }
            
            if(hashMap.find(sum) == hashMap.end()) hashMap[sum] = i;
        }
       
        return maxLen;
    }
};


