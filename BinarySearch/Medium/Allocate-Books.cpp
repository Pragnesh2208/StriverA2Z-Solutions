/*
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/
bool isAllocationPossible(int mid , vector<int>&arr , int &s) {
    int student = 1;
    int pages = 0;
    int n = arr.size();
    int index = 0 ;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > mid) return 0;
        if(pages + arr[i] > mid) {
            student++;
            pages = arr[i];
        } else pages += arr[i];
    }
    
    // cout<<mid<<" "<<student<<endl;
    return s >= student;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n ) return -1;
    

    int ans = -1;
    int sum = 0;
    int left = INT_MAX;
    for(int i = 0 ; i < n ;i++) {
        sum += arr[i];
        left = min(left , arr[i]);
    }

    int right = sum;

    while(left <= right){
        int mid = left + (right - left) / 2;
        // cout<<"left : "<<left<<" "<<"right : "<<right<<endl;
        if(isAllocationPossible(mid , arr , m)) {
            ans = mid;
            right = mid - 1;
        } else left = mid + 1;
    }
    return ans;
}