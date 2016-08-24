class Solution {
public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 1; i < n; ++i) {
            int count = 1;
            string temp;
            for (int j = 0; j < s.size(); ++j) {
                if (j == s.size() - 1 || s[j] != s[j + 1]) {
                    temp += to_string(count);
                    temp += s[j];
                    count = 1;
                }
                else {
                    count ++;
                }
            }
            s = temp;
        }
        return s;
    }
};