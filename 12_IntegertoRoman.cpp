class Solution {
public:
    string intToRoman(int num) {
        string flag[4][10] = {
                         {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                         {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                         {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                         {"", "M", "MM", "MMM"}
                        };
        string result;
        int mod1 = 1000;
        int sum = 3;
        while (mod1 != 0) {
            int temp = num / mod1;
            result += flag[sum][temp];
            num -= temp * mod1;
            sum--;
            mod1 /= 10;
        }
        return result;
    }
};