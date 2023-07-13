/*
Better Approch using Map 
Time Complexity = O(NLogN)
Space Complexity = O(N)
*/
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        map<long long ,int> hashMap;
        vector<int>ans;
        long long sum = 0;
        for(int i = 0 ; i < n ; i++) {
            sum += arr[i];
            if(sum == s) {
                return {1 , i + 1};
            } else if(hashMap.find(sum - s) != hashMap.end()) {
                return {hashMap[sum - s]+ 1 , i + 1};
            } 
            
            if(hashMap.find(sum) == hashMap.end()) {
                hashMap[sum] = i + 1;
            }
         }
         return {-1};
    }
};


/*
Optimal SOlution
Time Complexity = O(N)
Space Complexity = O(1)
*/

class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if(n == 0  || s == 0) return {-1};
        long long curSum = 0;
        long long startIndex = 0 , curIndex = 0;
        while(curIndex <= n ) {
            if(curSum  < s) {
                if(curIndex < n)
                curSum += arr[curIndex];
                
                curIndex++;
            } else if(curSum  == s) {
                return {startIndex + 1 , curIndex };
            } else if(curSum > s) {
                curSum -= arr[startIndex++];
            }
        }
        return {-1};
    }
};

