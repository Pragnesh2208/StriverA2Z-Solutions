/*
Brute Force Solution
Time Complexity = O(N ^ 3)
Space Complexity = O(N ^ 3)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>uniqueSet;
        for(int i = 0 ; i < n ; i++ ) {
            for(int j = i + 1 ; j < n ; j++) {
                for(int k = j + 1 ; k < n ; k++) {
                    if(nums[i] + nums[j] + nums[k] == 0)  {
                        vector<int>temp ={nums[i] , nums[j] , nums[k]};
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
Better Solution
Time Complexity = O(N ^ 2 * Log(N))
Space Complexity = O(N ^ 3)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>uniqueSet;
        map<int,int>hashMap;

        for(int i = 0 ; i < n ; i++) {
            for(int j = i + 1 ; j < n ;j++) {
                long long curSum = -(nums[i] + nums[j]);
                if(hashMap.find(curSum) != hashMap.end() && hashMap[curSum] != j && hashMap[curSum] != i) {
                    vector<int>temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[j]);
                    temp.push_back(nums[hashMap[curSum]]); 

                    sort(temp.begin() , temp.end());
                    uniqueSet.insert(temp);
                }
                hashMap[nums[j]]= j;
            }
        }
        vector<vector<int>> ans (uniqueSet.begin() , uniqueSet.end());
        return ans;
    }
};

/*
Better Solution
Time Complexity = O(N ^ 2)
Space Complexity = O(N ^ 3)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>>uniqueSet;
        sort(nums.begin()  , nums.end());
        int firPtr = 0;
        while(firPtr < n) {
            
            int secPtr = firPtr + 1;
            int thiPtr = n - 1;
            while(secPtr < n && thiPtr < n && secPtr < thiPtr) {
                int sum = nums[firPtr] + nums[secPtr] + nums[thiPtr];
                if(sum > 0 ) {
                    thiPtr--;
                } else if( sum < 0) secPtr++;
                else {
                    vector<int>temp;
                    temp.push_back(nums[firPtr]);
                    temp.push_back(nums[secPtr]);
                    temp.push_back(nums[thiPtr]);
                    
                    sort(temp.begin() , temp.end());
                    uniqueSet.insert(temp);

                    int prev = nums[secPtr];
                    while(secPtr < n && prev == nums[secPtr]) secPtr++;
                    prev = nums[thiPtr];
                    while(thiPtr >= 0 && prev == nums[thiPtr]) thiPtr--;
                }
            }

            int prev = nums[firPtr];
            while(firPtr < n && prev == nums[firPtr]) firPtr++;
        }

        vector<vector<int>> ans (uniqueSet.begin() , uniqueSet.end());
        return ans;
    }
};

/*
Optimal Solution
Time Complexity = O(N^2)
space Complexity = O(1)
*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin()  , nums.end());
        int firPtr = 0;
        vector<vector<int>>ans;
        while(firPtr < n) {
            
            int secPtr = firPtr + 1;
            int thiPtr = n - 1;
            while(secPtr < n && thiPtr < n && secPtr < thiPtr) {
                int sum = nums[firPtr] + nums[secPtr] + nums[thiPtr];
                if(sum > 0 ) {
                    int prev = nums[thiPtr];
                    while(thiPtr >= 0 && prev == nums[thiPtr]) thiPtr--;

                } else if( sum < 0){ 
                    int prev = nums[secPtr];
                    while(secPtr < n && prev == nums[secPtr]) secPtr++;
                    }
                else {
                    vector<int>temp;
                    temp.push_back(nums[firPtr]);
                    temp.push_back(nums[secPtr]);
                    temp.push_back(nums[thiPtr]);
                    
                    sort(temp.begin() , temp.end());
                  
                    ans.push_back(temp);
                    int prev = nums[secPtr];
                    while(secPtr < n && prev == nums[secPtr]) secPtr++;
                    prev = nums[thiPtr];
                    while(thiPtr >= 0 && prev == nums[thiPtr]) thiPtr--;
                }
            }

            int prev = nums[firPtr];
            while(firPtr < n && prev == nums[firPtr]) firPtr++;
        }

    
        return ans;
    }
};