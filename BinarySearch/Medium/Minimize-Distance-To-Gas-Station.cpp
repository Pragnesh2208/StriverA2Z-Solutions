/*
Time Complexity = o(100*N)
Space Complexity = O(1)

How to Find number of for loop iteration
Log(range/precision)

here range is 1e9 
and precision is 1e-6
so iteration is Log(1e9 / 1e-6 ) = Log(1e9 * 1e6) = Log(1e15) which is equvivalent to 47
*/

bool isGood(long double dist ,vector<int> &arr, int k ) {
	int n = arr.size();
	int takenStation = 0 ;
	int index = 0 ;
	long double  cur = arr[index++];
	while(index < n ) {
		long double temp =  arr[index];
		if(cur + dist < temp) { 
			cur += dist ; 

			if(takenStation + 1 > k ) return false;
			takenStation++;

		} else {
			cur = arr[index++];
		}
	} 
	return takenStation <= k;
}

long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.	
	long double left = 0 , right = 0;
	int n = arr.size();
	for(int i = 1 ; i < n ; i++){
		long double temp=  arr[i] - arr[i-1];
		 right = max(right , temp);
		}

	for(int i = 0 ; i < 47 ; i++){
		long double mid = left + (right - left) / 2;
		if( isGood(mid , arr , k)) right = mid;
		else left = mid;

		// cout<<setprecision(20)<<right<<endl;
	}


	
	return right;
}