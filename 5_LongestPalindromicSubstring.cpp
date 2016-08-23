//Solution1
class Solution {
public:
    string longestPalindrome(string s) {
        int dp[1005][1005] = {0};
        int start = 0, length = 1;
        for (int i = 0; i < s.size(); ++i) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                start = i;
                length = 2;
            }
        }
        for (int k = 2; k < s.size(); ++k) {
            for (int i = 0; i < s.size() - k; ++i) {
                if (s[i] == s[i + k] && dp[i + 1][i + k - 1] == 1) {
                    dp[i][i + k] = 1;
                    start = i;
                    length = k + 1;
                }
            }
        }
        return s.substr(start,length);
    }
};
//Solution2
class Solution {
private:
    int helper(const string& s, int left, int right) {
        int length = 0;
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            length = right - left + 1;
            left--;
            right++;
        }
        return length;
    }
public:
    string longestPalindrome(string s) {
        int start = 0, length = 0;
        for (int i = 0; i < s.size() ; ++i) {
            int l1 = helper(s, i, i);
            if (l1 > length) {
                length = l1;
                start = i - (length / 2);
            }
        }    
        for (int i = 0; i < s.size() - 1; ++i) {
            int l2 = helper(s, i, i+1);
            if (l2 > length) {
                length = l2;
                start = i - (length - 2) / 2;
            }
        }
        return s.substr(start, length);
    }
};