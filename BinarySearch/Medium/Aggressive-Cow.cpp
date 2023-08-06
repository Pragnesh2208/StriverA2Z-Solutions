/*
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	long long t;
	cin>>t;
	while(t--) {
		int n , c;
		cin>>n>>c;
		vector<int>a(n , 0);
		int ans;
		int left = 0 , right = INT_MIN;
		for(int i = 0 ; i < n ; i++) {
			cin>>a[i];
			right = max(right , a[i]);
		}
		
		sort(a.begin() , a.end());
		
		while(left <= right) {
			int mid = left + ( right - left) /2;
			int cnt = 1 , prev = a[0];
			for(int i = 1 ; i < n ;i++) {
				if(a[i] - prev >= mid) {
					cnt++;
					prev = a[i];
				}
			}
			
			if(cnt >= c) {
				ans = mid;
				left = mid + 1;
			}
			else right = mid - 1;
		}
		cout<<ans<<endl;
		
	}
	return 0;
}