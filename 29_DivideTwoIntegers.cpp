class Solution {
public:
    int divide(int dividend, int divisor) {
        long long ldividend = dividend;
        long long ldivisor = divisor;
        int flag = 1;
        if (ldividend < 0) {
            ldividend = -ldividend;
            flag = -flag;
        }
        if (ldivisor < 0) {
            ldivisor = -ldivisor;
            flag = -flag;
        }
        long long result = 0;
        while (ldivisor <= ldividend) {
            long long count = ldivisor;
            long long temp = 1;
            long long tempDividend = ldividend;
            while ( !(count <= tempDividend && (count << 1) > tempDividend)) {
                count <<= 1;
                temp <<= 1;
            }
            result += temp;
            ldividend -= count;
        }
        if (flag < 0) {
            if (result > 0x80000000) {
                return 0x7FFFFFFF;
            }
            else {
                return -result;
            }
        }
        else {
            if (result > 0x7FFFFFFF) {
                return 0x7FFFFFFF;
            }
            else {
                return result;
            }
        }
        
    }
};