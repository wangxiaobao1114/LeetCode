class Solution {
public:
    int strStr(string haystack, string needle) {
        if (haystack.size() == 0 && needle.size() == 0) {
            return 0;
        }
        if (haystack.size() < needle.size()) {
            return -1;
        }
        for (int i = 0; i < haystack.size() - needle.size() + 1; ++i) {
            int flag = 1;
            for (int j = 0; j < needle.size(); ++j) {
                if (haystack[i + j] != needle[j]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 1) {
                return i;
            }
        }
        return -1;
    }
};