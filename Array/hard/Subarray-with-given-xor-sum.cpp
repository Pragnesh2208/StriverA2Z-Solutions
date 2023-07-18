/*
Optimal solution
Time Complexity = O(NLogN)
space Complexity = O(N)
*/
int Solution::solve(vector<int> &A, int B) {
    int cnt = 0;
    int n = A.size();
    map<int, int>hashMap;
    int xorSum = 0;
    for(int i = 0 ; i < n ; i++) {
        xorSum ^= A[i];
        if(xorSum == B) {
            cnt++;
        } 
        if(hashMap.find(xorSum ^ B) != hashMap.end() ) cnt+= hashMap[xorSum ^ B];
            hashMap[xorSum]++;
    }
    return cnt;
}
