//solution1
class Solution {
private:
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
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int rex = reverse(x);
        if (rex == 0 && x != 0) { //溢出(不是因为等于0而得到rex = 0)
            return false;
        }
        if (rex == x) {
            return true;
        }
        return false;
    }
};
//Solution2
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0) ) {
            return false;
        }
        int sum = 0;
        while (x > sum) {
            int temp = x % 10;
            sum = sum * 10 + temp;
            x /= 10;
        }
        if (x == sum || x == sum / 10) {
            return true;
        }
        return false;
    }
};