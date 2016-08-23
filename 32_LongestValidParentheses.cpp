class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return 0;
        }
        int result = 0;
        int dp[s.size()] = {0};
        if (s[1] == ')' && s[0] == '(') {
            dp[1] = 2;
            result = 2;
        } 
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(') {
                dp[i] = 0;
            }
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = dp[i - 2] + 2;
                    result = max(result,dp[i]);
                }
                if (s[i - 1] == ')') {
                    int j = dp[i - 1];
                    if (i - j - 1 >= 0 && s[i - j - 1] == '(') {
                        dp[i] = dp[i - 1] + dp[i - j - 2] + 2;
                        result = max(result,dp[i]);
                    }
                    else {
                        dp[i] = 0;
                    }
                }
            }
        }
        return result;
    }
};