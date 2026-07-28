class Solution {
public:
    // {length_of_str@}
    string encode(vector<string>& strs) {
        int n = strs.size();
        string encoded = "";

        for(int i = 0; i < n; i++){
            string str = strs[i];
            int m = str.length();

            encoded += to_string(m);
            encoded += "@";
            encoded += str;
        }

        cout << encoded << '\n';

        return encoded;
    }

    vector<string> decode(string encoded) {
        vector<string> ans;
        int n = encoded.length();

        int i = 0;

        while(i < n){
            int j = i;
            int counter = 0;
            string temp;

            while(isdigit(encoded[j])){
                temp.push_back(encoded[j]);
                counter++;
                j++;
            }

            int expo = counter - 1;
            int lenToTake = 0;

            for(int i = 0; i < counter; i++){
                lenToTake += ((temp[i] - '0') * pow(10, expo));
                expo--;
            }

            cout << lenToTake << '\n';
            
            if(i + counter + 1 < n){
                ans.push_back(encoded.substr(i + counter + 1, lenToTake));
                i += (lenToTake + counter + 1);
            }
            else{
                ans.push_back("");
                i += 2;
            }
        }

        return ans;
    }
};
