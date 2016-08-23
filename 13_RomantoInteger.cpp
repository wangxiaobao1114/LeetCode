class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == 'M') {
                if (i - 1 >= 0 && s[i-1] == 'C') {
                    result += 800;
                }
                else {
                    result += 1000;
                }
            }
            if (s[i] == 'D') {
                if (i - 1 >= 0 && s[i-1] == 'C') {
                    result += 300;
                }
                else {
                    result += 500;
                }
            }
            if (s[i] == 'C') {
                if (i - 1 >= 0 && s[i-1] == 'X') {
                    result += 80;
                }
                else {
                    result += 100;
                }
            }
            if (s[i] == 'L') {
                if (i - 1 >= 0 && s[i-1] == 'X') {
                    result += 30;
                }
                else {
                    result += 50;
                }
            }
            if (s[i] == 'X') {
                if (i - 1 >= 0 && s[i-1] == 'I') {
                    result += 8;
                }
                else {
                    result += 10;
                }
            }
            if (s[i] == 'V') {
                if (i - 1 >= 0 && s[i-1] == 'I') {
                    result += 3;
                }
                else {
                    result += 5;
                }
            }
            if (s[i] == 'I'){
                result += 1;
            }
        }
        return result;
    }
};