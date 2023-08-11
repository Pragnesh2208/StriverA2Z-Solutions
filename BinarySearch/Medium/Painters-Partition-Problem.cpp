/*
Time Complexity = O(Log(maxVal)*N)
Space Complexity = O(1)
*/

#include<bits/stdc++.h>
using namespace std;
bool isPainted(long long time , vector<int>&a , int k) {
    long long takenPainter = 1 ;
    long long tempTime = time;
    int n = a.size();
    for(int i = 0 ; i < n ; i++) {
        if(a[i] > time) return false;
        if(tempTime - a[i] < 0) {
            takenPainter++;
            tempTime = time ;
            tempTime -= a[i];
            
        } else tempTime -= a[i];
    }
    return takenPainter <= k;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int n = boards.size();
    long long left = 0 , right = 0;

    for(int i = 0 ; i < n ; i++) right += boards[i];


    while(right > left + 1) {
        long long time = left + (right - left) / 2;

        if(isPainted(time , boards , k)) right = time;
        else left = time;

    }
    return right;
}