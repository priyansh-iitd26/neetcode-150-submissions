class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> mp;

        vector<int> ans;

        for(int i = 0; i < n; i++){
            int candidate = target - nums[i];

            if(mp.find(candidate) != mp.end()){
                ans.push_back(mp[candidate]);
                ans.push_back(i);
                break;
            }

            mp[nums[i]] = i;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
