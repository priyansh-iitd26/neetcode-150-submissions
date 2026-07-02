class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.length(), m = t.length();
        vector<int> freq(26, 0); //stores frequency count of string s

        for(int i = 0; i < n; i++) freq[s[i] - 'a']++;

        for(int i = 0; i < m; i++){
            int curr_freq = freq[t[i] - 'a'];
            
            if(curr_freq == 0) return false;

            freq[t[i] - 'a']--;
        }

        for(int i = 0; i < 26; i++){
            if(freq[i] != 0) return false;
        }

        return true;
    }
};
