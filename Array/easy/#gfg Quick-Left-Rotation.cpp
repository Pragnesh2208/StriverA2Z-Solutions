/*
Time Complexity = O(N)
Space Complexity = O(1)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	private : 
	void reverse(int arr[] ,  int start ,int end) {
	    while(start < end) {
	        int temp = arr[start];
	        arr[start] = arr[end];
	        arr[end]  = temp;
	        start++;
	        end--;
	    }
	}
	
	public:
	void leftRotate(int arr[], int k, int n) 
	{ 
	    k %= n;
	   // Your code goes here
	   reverse(arr , 0 , n - 1);
	   reverse(arr , 0 , n- k -1);
	   reverse(arr , n - k  ,n-1 );
	   
	} 
};

//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin >> n;
	    int k;
	    cin >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }

        Solution ob;
        ob.leftRotate(a,k,n);
        
        for (int i = 0; i < n; i++) 
        	cout << a[i] << " "; 

	    cout << "\n";
	     
    }
    return 0;
}



// } Driver Code Ends