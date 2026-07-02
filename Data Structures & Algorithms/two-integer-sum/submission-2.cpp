class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<pair<int, int>> vp;

        for(int i = 0; i < n; i++) vp.push_back({nums[i], i});

        sort(vp.begin(), vp.end());
        
        int i = 0, j = n - 1;
        vector<int> ans;

        while(i < j){

            int sum = vp[i].first + vp[j].first;

            if(sum == target){
                ans.push_back(vp[i].second);
                ans.push_back(vp[j].second);
                break;
            }

            else if(sum < target) i++;
            else j--;
        }

        sort(ans.begin(), ans.end());

        return ans;
    }
};
