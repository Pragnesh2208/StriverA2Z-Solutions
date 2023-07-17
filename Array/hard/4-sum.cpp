/*
Brute Force Solution
Time Complexity = O(N^4)
Space Complexity =O(N^4)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>uniqueSet;
        for(int firPtr = 0 ; firPtr < n ; firPtr++) {
            for(int secPtr = firPtr + 1 ; secPtr < n ; secPtr++)
            {
                for(int thiPtr = secPtr + 1 ; thiPtr < n ; thiPtr++) {
                     for(int fouPtr = thiPtr + 1 ; fouPtr < n ; fouPtr++) {
                        long long sum = nums[firPtr] + nums[secPtr]  ;
                        if(sum ==  target - nums[fouPtr] - nums[thiPtr]) {
                            vector<int> temp;
                            temp.push_back(nums[firPtr]);
                            temp.push_back(nums[secPtr]);
                            temp.push_back(nums[thiPtr]);
                            temp.push_back(nums[fouPtr]);

                            sort(temp.begin() , temp.end());
                            uniqueSet.insert(temp);
                        }
                    }
                }
            }
        }
         
        vector<vector<int>> ans (uniqueSet.begin() , uniqueSet.end());
        return ans;
    }
};


/*
Better Solution
Time Complexity = O(N^3 LogN)
Space Complexity = O(N^4)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        set<vector<int>>uniqueSet;
        map<long long , int>hashMap;
        for(int i = 0 ; i < n ;i++) {
            hashMap[nums[i]] = i;
        }
        for(int firPtr = 0 ; firPtr < n ; firPtr++) {
            for(int secPtr = firPtr + 1 ; secPtr < n ; secPtr++)
            {
                for(int thiPtr = secPtr + 1 ; thiPtr < n ; thiPtr++) {
                        long long sum = 0;
                        sum -= nums[firPtr] ;
                        sum -= nums[secPtr]  ;
                        sum += target;
                        sum -= nums[thiPtr];
                        if(hashMap.find(sum) != hashMap.end() && hashMap[sum] > thiPtr) {
                            int fouPtr = hashMap[sum];
                            vector<int> temp;
                            temp.push_back(nums[firPtr]);
                            temp.push_back(nums[secPtr]);
                            temp.push_back(nums[thiPtr]);
                            temp.push_back(nums[fouPtr]);

                            sort(temp.begin() , temp.end());
                            uniqueSet.insert(temp);
                        }
                }
            }
        }
         
        vector<vector<int>> ans (uniqueSet.begin() , uniqueSet.end());
        return ans;
    }
};

/*
Optimal Solution
Time Complexity = O(N^3)
Space Complexity = O(1)
*/
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin() , nums.end());
        int firPtr = 0;
        while(firPtr < n) {
            int secPtr = firPtr + 1;
            while(secPtr < n)
            {
                int thiPtr = secPtr + 1 , fouPtr = n - 1;
                while(thiPtr < fouPtr) {
                    long long sum = 0;
                    sum += nums[firPtr];
                    sum += nums[secPtr] ;
                    sum += nums[thiPtr];
                    sum += nums[fouPtr];

                    if(sum < target) {
                        thiPtr++;
                    }

                    else if(sum > target) {
                        fouPtr--;
                    }

                    else {
                        vector<int> temp;
                        temp.push_back(nums[firPtr]);
                        temp.push_back(nums[secPtr]);
                        temp.push_back(nums[thiPtr]);
                        temp.push_back(nums[fouPtr]);
                        ans.push_back(temp);
                        int prev = nums[thiPtr];
                        while(thiPtr < fouPtr && prev == nums[thiPtr]) thiPtr++;
                        prev = nums[fouPtr];
                        while(fouPtr > thiPtr && prev  == nums[fouPtr]) fouPtr--;  
                    } 
                }
                 
                int prev = nums[secPtr];
                while (secPtr < n && prev == nums[secPtr]) secPtr++;                 
            }


            int prev = nums[firPtr];
            while(firPtr < n && prev == nums[firPtr]) firPtr++;
        }
         
 
        return ans;
    }
};