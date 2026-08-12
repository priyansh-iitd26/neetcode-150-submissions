class Solution {
public:
    bool isPalindrome(string s) {
        string temp = "";
        int n = s.length();
        
        for(int i = 0; i < n; i++){
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')){
                temp += tolower(s[i]);
            }
        }

        // cout << temp << '\n';

        int i = 0, j = temp.size() - 1;

        while(i < j){
            if(temp[i] == temp[j]){
                i++;
                j--;
            }
            else return false;
        }

        return true;
    }
};
