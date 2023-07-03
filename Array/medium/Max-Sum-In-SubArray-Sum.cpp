/*
Time Complexity = O(N)
Space Complexity = O(1)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends


class Solution{
    
    public:
        long long pairWithMaxSum(long long arr[], long long N)
    {
        // Your code goes here
        long long  pairWithMaxSum = 0;
        for(int j = 0, i = 1;  j < N && i < N ; i++ , j++) {
            pairWithMaxSum = max(arr[j]  + arr[i] , pairWithMaxSum);
        }
       return pairWithMaxSum;
    }
};



//{ Driver Code Starts.
int main() 
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll a[n];
	    for(ll i=0;i<n;i++)
		    cin>>a[i];
		Solution ob;
	    cout<<ob.pairWithMaxSum(a,n)<<endl;
	}
	return 0;
}


// } Driver Code Ends