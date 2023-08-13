#include <bits/stdc++.h>

int kthElement(vector<int> &arr1, vector<int>& arr2, int n, int m, int k){
    // Write your code here
    int N1 = arr1.size();
    int N2 = arr2.size();
    int left = 0 , right = N1;
    if(N2 > N1) return kthElement(arr2, arr1,n, m,  k);
    if(k < N1) right = k;
    if( k - N2 > 0 ) left = k - N2;

    while(left <= right) {
        int median1 = left + (right - left) / 2;
        int median2 = k - median1;

        int right1 = median1 == N1 ? INT_MAX : arr1[median1];
        int left1= median1 == 0 ? INT_MIN : arr1[median1 - 1];
        int right2 = median2 == N2 ? INT_MAX : arr2[median2];
        int left2 = median2 == 0  ? INT_MIN : arr2[median2 - 1];
        
        if(right1 >= left2 && right2 >= left1) {            
            return max(left1 , left2);
        } else if(right1 <= left2) {
            left =  median1 + 1;
        } else right = median1 - 1;
    }
    
    return -1;
}