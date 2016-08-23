//Solution1 BFS
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string digMap[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> v;
        if (digits.size() == 0) {
            return v;
        }
        queue<string> q;
        for (int i = 0; i < digMap[digits[0] - '0'].size(); ++i) {
            q.push(string(1,digMap[digits[0] - '0'][i] ));
        }
        for (int i = 1; i < digits.size(); ++i) {
            int l = q.size();
            for (int j = 0; j < l; ++j) {
                string temp1 = q.front();
                q.pop();
                for (int k = 0; k < digMap[digits[i] - '0'].size(); ++k) {
                    string temp2 = temp1 + digMap[digits[i] - '0'][k];
                    q.push(temp2);
                }
            }
        }
        while (!q.empty()) {
            v.push_back(q.front());
            q.pop();
        }
        return v;
    }
};

//Solution2 DFS
class Solution {
private:
    string digMap[10] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void dfs(vector<string>& v, string& tempStr, int index, string& digits) {
        if (index == digits.size()) {
            v.push_back(tempStr);
            return;
        }
        for (int i = 0; i < digMap[digits[index] - '0'].size(); ++i) {
            //tempStr += digMap[digits[index] - '0'][i];
            tempStr.push_back(digMap[digits[index] - '0'][i]); //string的push_back和pop_back以前没用过
            dfs(v,tempStr,index + 1,digits);
            tempStr.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.size() == 0) {
            return result;
        }
        string tempStr;
        dfs(result,tempStr,0,digits);
        return result;
    }
};