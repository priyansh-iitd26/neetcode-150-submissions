class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i = 0; i < n; i++) mp[nums[i]]++;

        vector<pair<int, int>> arr;

        for(auto &it : mp)
            arr.push_back({it.second, it.first});

        sort(arr.rbegin(), arr.rend());

        vector<int> result;

        for(int i = 0; i < k; i++)
            result.push_back(arr[i].second);

        return result;
    }
};
