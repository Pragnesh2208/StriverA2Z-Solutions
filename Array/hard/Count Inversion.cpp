/*
Time Complexity = O(NLogN)
Space Complexity = O(N)
*/

int merge(vector<int>&arr , int low , int mid , int high) {
    int left = low , right = mid + 1;
    int count = 0;
    vector<int>temp;
    while( left <= mid && right <= high ) {
       
        if(arr[left] > arr[right]) {
            count += (mid - left + 1) ;
            temp.push_back(arr[right++]);
        }
        else {
            temp.push_back(arr[left++]);
        } 
    }
    
    while( left <= mid ) {
        temp.push_back(arr[left++]);
    }
    
    while(right <= high ) {
        temp.push_back(arr[right++]);
    }
    
    for(int i = 0 ; i < temp.size() ; i++) {
        arr[i + low] = temp[i];
    }
    return count;
}

int mergeSort(vector<int>&A ,  int low , int high  ) {
    
    if(low >= high) return 0;
  
        int mid =  (high + low) / 2;
        int cnt = mergeSort(A , low , mid);
        cnt += mergeSort(A , mid + 1 , high);
        cnt +=merge(A , low , mid , high);
        return cnt;
    
}


int Solution::countInversions(vector<int> &A) {
    int n = A.size();
    return mergeSort(A , 0 , n - 1);
}
