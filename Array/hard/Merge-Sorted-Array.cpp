/*
Optimal Solution
Time Complexity = O(N + M)
space Complexity = O(1)
*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        int firstPtr = m - 1;
        int secondPtr = n - 1;

        while(firstPtr >= 0 && secondPtr >=0 ) {
            if(nums1[firstPtr] > nums2[secondPtr]) {
                nums1[index] = nums1[firstPtr--];
            }
            else {
                nums1[index] = nums2[secondPtr--];
            }
            index--;
        }

        while(secondPtr >=0) {
            nums1[index--] = nums2[secondPtr--];
        }

    }
};