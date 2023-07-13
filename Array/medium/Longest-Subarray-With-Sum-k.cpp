/*
Optimal Solution
Time Complexity = O(NLogN)
Space Complexity = O(N)
*/
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int k) 
    { 
        // Complete the function
        map<long long,int>hashMap;
        int maxLen = 0;
        long long sum = 0;
        for(int i = 0 ; i < N ; i++) {
            sum += A[i];
          
            
            if(sum == k) {
                maxLen = max(i + 1, maxLen);
            }
            else if(hashMap.find(sum - k) != hashMap.end()) {
                maxLen = max( i  - hashMap[sum - k]  , maxLen );
            }
            
              if(hashMap.find(sum) == hashMap.end())
            hashMap[sum] = i;
        }
     
        return maxLen;
    } 

};
