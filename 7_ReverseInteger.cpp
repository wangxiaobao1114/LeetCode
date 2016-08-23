//Solution1
class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            result = result * 10 +  temp;
            if (result > 0x7FFFFFFF || result < -0x7FFFFFFF) {
                return 0;
            }
        }
        return result;
    }
};
//Solution2
class Solution {
public:
    int reverse(int x) {
        int result = 0;
        while (x != 0) {
            int temp = x % 10;
            x /= 10;
            int newResult = result * 10 +  temp;
            if ( (newResult - temp) / 10 != result) {
                return 0;
            }
            result = newResult;
        }
        return result;
    }
};