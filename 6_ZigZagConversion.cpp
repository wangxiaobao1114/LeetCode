class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> v(numRows);
        int j = 0;
        for (int i = 0; i < s.size(); ++i) {
            if ( (i / (numRows - 1) ) % 2 == 0) {
                v[j].insert(v[j].end(), s[i]);
                j ++;
            } 
            if ( (i / (numRows - 1)) % 2 == 1) {
                v[j].insert(v[j].end(), s[i]);
                j--;
            }
       }
       string result;
       for (int i = 0; i < v.size(); ++i) {
           result += v[i];
       }
       return result;
    }
};