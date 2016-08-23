class Solution {
    void dfs(vector<string>& v, string& s, int n,int left) {
        if (s.size() == n) {
            v.push_back(s);
            return;
        }
        int right = s.size() - left; 
        if (left < n / 2) {
            s.push_back('(');
            dfs(v,s,n,left+1);
            s.pop_back();
        } 
        if (right < left) {
            s.push_back(')');
            dfs(v,s,n,left);
            s.pop_back();
        }
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        if (n == 0) {
            return result;
        }
        string s;
        dfs(result,s,2*n,0);
        return result;
    }
};