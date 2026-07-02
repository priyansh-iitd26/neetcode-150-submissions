class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]]++;

        for(auto &e : mp){
            if(e.second > 1) return true;
        }

        return false;
    }
};