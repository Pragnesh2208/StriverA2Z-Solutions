/*
Time Complexity = O(NLogN)
Space Complexity = O(1)
*/
class Solution {
    private :
    int merge(vector<int>&arr , int low , int mid , int high) {
        int left = low ;
        int right = mid + 1;
        int count = 0;
        vector<int>temp;
        while(left <= mid && right <= high) {
            long long temp = arr[right];
            temp *= 2;
            if( temp <= INT_MAX && arr[left] > temp) {
                count+= (mid - left + 1);
                right++;
            } 
            else {
                left++;
            }
        }
        left = low;
        right = mid + 1;
        while(left <= mid && right <= high) {
            if(arr[left] >= arr[right]) temp.push_back(arr[right++]);
            else temp.push_back(arr[left++]);
        }
        while(left <= mid) {temp.push_back(arr[left++]);}
        while(right <= high) {
            temp.push_back(arr[right++]);
        }

        for(int i = 0 ; i < temp.size() ; i++) {
            arr[i + low] = temp[i];
        }
    
        return count;
    } 
    int mergeSort(vector<int>&arr , int low , int high) {
        if(low >= high) return 0;
        int mid = (low + high) / 2;
        int count = mergeSort(arr , low , mid);
            count += mergeSort(arr  , mid + 1 , high);
            count += merge(arr , low , mid , high);
        return count;
    }
public:
    int reversePairs(vector<int>& nums) {
     return mergeSort(nums , 0 , nums.size() - 1);   
    }
};

