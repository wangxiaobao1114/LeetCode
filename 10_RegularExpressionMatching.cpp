class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[s.size() + 1][p.size() + 1];
        dp[0][0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            dp[i][0] = false;
        }
        for (int j = 1; j <= p.size(); ++j) {
             //p[j-2]一定存在,*不会打头！
             if (p[j - 1] == '*' &&  dp[0][j - 2])  {
                dp[0][j] = true;
            }
            else {
                dp[0][j] = false;
            }
        }
    
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = 1; j <= p.size(); ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] =  (s[i - 1] == p[j - 1] || p[j - 1] == '.') && dp[i - 1][j - 1];
                }
                else {
                    //重复两次或更多   dp[i-1][j]  如：aaa与.*
                    // * 不会打头，所以p[j - 2]一定存在
                    bool b1 = (s[i - 1] == p[j - 2] || p[j - 2] == '.') && (dp[i - 1][j - 1] || dp[i - 1][j]);
                    bool b2 =  dp[i][j - 1];  //重复1次
                    bool b3 =  dp[i][j - 2];  //重复0次
                    dp[i][j] = b1 || b2 || b3;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};