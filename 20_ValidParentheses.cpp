class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 0) {
            return true;
        }
        stack<char> sta;
        sta.push(s[0]);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                sta.push(s[i]);
                continue;
            }
            else {
                if ( sta.empty() ) {  // "()]"
                    return false;
                }
                if (s[i] == ')' && sta.top() != '(') {
                     return false;
                }
                if (s[i] == ']' && sta.top() != '[') {
                     return false;
                }
                if (s[i] == '}' && sta.top() != '{') {
                     return false;
                }
                sta.pop();
            }
            
        }
        return sta.empty();
    } 
};