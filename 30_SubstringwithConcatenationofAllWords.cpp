class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        unordered_map<string, int> count;
        vector<int> result;
        for (int k = 0 ; k < words.size(); ++k) {
            count[words[k]]++;    
        }
        //s.size() - words.size() * len 结果是个unsigned;
        int n = s.size(), m = words.size();
        for (int i = 0; i <= n - m * len; i++) {
            unordered_map<string, int> hash;
            int flag = 0;
            for (int j = i; j < i + words.size() * len  ; j += len) {
                string temp = s.substr(j, len);
                hash[temp]++;
                if (hash[temp] > count[temp]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0) {
                result.push_back(i);
            }
        }
        return result;
    }
};