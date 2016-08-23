//Solution1 
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result = 0;
        int letters[256] = {0};
        int tempResult;
        for (int i = 0; i < s.size(); ++i) {
            if (i + result >= s.size()) {
                break;
            }
            tempResult = 1;
            memset(letters, 0 , sizeof(letters));
            letters[s[i]] = 1;
            for (int j = i + 1; j < s.size(); ++j) {
                if (letters[s[j]] == 0) {
                    tempResult++;
                    letters[s[j]] = 1;
                }
                else {
                    break;
                }
            }
            result = max(result, tempResult);
        }
        return result;
    }
};

//Solution2
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int letters[256] = {0};
        int left = 0;
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (letters[s[i]] != 0) {
                while (s[left] != s[i]) {
                    letters[s[left]] = 0;
                    left ++;
                }
                letters[s[left]] = 0;
                left ++;
            }
            letters[s[i]] = 1;
            result = max(result, i - left + 1);
        }
        return result;
    }
};

//Solution3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int lastIndex[256]; // 上次出现该字符的下标
        int left = 0;           //当前维护的字串的最左端
        int result = 0;
        memset(lastIndex, -1, sizeof(lastIndex));
        for (int i = 0; i < s.size(); ++i) {
            if (lastIndex[s[i]] >= left) { //在这个字串内有重复 >= left
                left = lastIndex[s[i]] + 1;
            }
            lastIndex[s[i]] = i;
            result = max(result, i - left + 1);
        }
        return result;
    }
};