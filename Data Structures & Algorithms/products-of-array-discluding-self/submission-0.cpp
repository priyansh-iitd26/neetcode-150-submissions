class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix_mult(n);
        vector<int> suffix_mult(n);
        prefix_mult[0] = nums[0];
        suffix_mult[n - 1] = nums[n - 1];
        for(int i = 1; i < n; i++) prefix_mult[i] = (nums[i] * prefix_mult[i - 1]);
        for(int i = n - 2; i >= 0; i--) suffix_mult[i] = (nums[i] * suffix_mult[i + 1]);

        vector<int> ans;

        for(int i = 0; i < n; i++){
            if(i == 0) ans.push_back(suffix_mult[1]);
            else if(i == n - 1) ans.push_back(prefix_mult[n - 2]);
            else ans.push_back(prefix_mult[i - 1] * suffix_mult[i + 1]);
        }

        return ans;
    }
};
