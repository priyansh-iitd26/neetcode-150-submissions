#include<bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    ll maximumAlternatingSubarraySum(vector<int>& nums){
        int n = nums.size();
        
        // max_even[i] = max alternating sum ending at index i where nums[i] is added
        // max_odd[i]  = max alternating sum ending at index i where nums[i] is subtracted

        vector<ll> max_even(n, 0);
        vector<ll> max_odd(n, 0);
        
        // for the first element, it can only start a new subarray (added)
        max_even[0] = nums[0];
        
        max_odd[0] = LLONG_MIN;
        
        ll ans = max_even[0];
        
        for(int i = 1; i < n; i++){
            // case 1: nums[i] is added (+) 
            // we can either start a fresh subarray here, or continue an alternating chain from max_odd[i-1]
            
            if(max_odd[i-1] != LLONG_MIN)
                max_even[i] = max((ll)nums[i], max_odd[i-1] + nums[i]);
            
            else
                max_even[i] = nums[i];
            
            // case 2: nums[i] is subtracted (-)
            // we can only do this if a valid chain existed before it (max_even[i-1] must be valid)
            
            if(max_even[i-1] != LLONG_MIN)
                max_odd[i] = max_even[i-1] - nums[i];
        
            else
                max_odd[i] = LLONG_MIN;
            
            
            // tracking the highest sum over all i
            ans = max({ans, max_even[i], max_odd[i]});
        }
        
        return ans;
    }
};

int main() {
    Solution solver;

    vector<int> nums1 = {3, -1, 1, 2};
    cout << "Test 1 Input: {3, -1, 1, 2}" << endl;
    cout << "Maximum Alternating Subarray Sum: " << solver.maximumAlternatingSubarraySum(nums1) << "\n\n";

    vector<int> nums2 = {2, 2, 2, 2, 2};
    cout << "Test 2 Input: {2, 2, 2, 2, 2}" << endl;
    cout << "Maximum Alternating Subarray Sum: " << solver.maximumAlternatingSubarraySum(nums2) << "\n\n";

    vector<int> nums3 = {4, 2, 3};
    cout << "Test 3 Input: {4, 2, 3}" << endl;
    cout << "Maximum Alternating Subarray Sum: " << solver.maximumAlternatingSubarraySum(nums3) << "\n";

    return 0;
}
