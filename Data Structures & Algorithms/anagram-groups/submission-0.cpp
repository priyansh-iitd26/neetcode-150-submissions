class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> arr(n, vector<int>(27, 0));
        
        for(int i = 0; i < n; i++){
            string str = strs[i];
            for(int j = 0; j < str.size(); j++) arr[i][str[j] - 'a' + 1]++;
        }

        //we cannot use a vector<int> as a 'key' in hash table

        unordered_map<string, vector<string>> mp;

        for(int i = 0; i < n; i++){

            string key = "";

            for(int j = 1; j <= 26; j++){
                key += to_string(arr[i][j]) + "#";
            }

            mp[key].push_back(strs[i]);
        }

        vector<vector<string>> ans;

        for(auto &it : mp)
            ans.push_back(it.second);

        return ans;
        
    }
};
