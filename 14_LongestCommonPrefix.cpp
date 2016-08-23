class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int length = 0;
        if (strs.size() == 0) {
            return "";
        }
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 0; j < strs.size() - 1; ++j) {
                if (strs[j].size() == i|| strs[j][i] != strs[j + 1][i]) {
                    return strs[0].substr(0,length);
                }
            }
            length++;
        }
        return strs[0].substr(0,length);
    }
};