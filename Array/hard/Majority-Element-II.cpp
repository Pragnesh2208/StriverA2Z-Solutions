/*
Time Complexity = O(N)
Space Complexity = O(N)
*/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int,int>hashMap;
        int n = nums.size();
        vector<int>ans;
        for(int i = 0 ; i < n ; i++) {
            hashMap[nums[i]]++;
        }
        for(const pair<int,  int>itr: hashMap) {
            if(itr.second > n / 3)ans.push_back(itr.first);
        }
        return ans;
    }
};


/*
Time Complexity = O(N)
Space Complexity = O(1)
*/

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        int freq[2] ={0 ,0};
        int ele1 = 0 , cnt1 =  0, ele2 = 0 , cnt2 = 0;
        for(int i = 0 ; i < n ; i++) {
            if(cnt1 == 0 && nums[i] != ele2) {
                ele1 = nums[i];
                cnt1++;
            }
            else if(cnt2 == 0 && nums[i] != ele1) {
                ele2 = nums[i];
                cnt2++;
            } else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else {
                cnt1--;
                cnt2--;
            }
        }

        for(int i = 0 ; i < n ;i++) {
            if(ele1 == nums[i]) freq[0]++;
            else if(ele2 == nums[i]) freq[1]++;
        }
        if(freq[0] > n / 3) ans.push_back(ele1);
        if(freq[1] > n / 3) ans.push_back(ele2);
        return ans;
    }
};