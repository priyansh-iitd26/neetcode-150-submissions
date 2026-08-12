class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int maxi = INT_MIN;

        for(auto &num : st){
            if(st.find(num - 1) == st.end()){
                // potential starting point of a sequence
                int len = 1;
                while(st.find(num + len) != st.end()){
                    len++;
                }
                maxi = max(maxi, len);
            }
            else continue;
        }

        return maxi == INT_MIN ? 0 : maxi;
    }
};
