class Solution {
public:
    int myAtoi(string str) {
        int start = 0;
        long long result = 0;
        int flag = 0;
        //开头多余空格的处理
        while (str[start] == ' ') {                                     
            start++;
        }
        if (str[start] == '+') {
            start++;
        }
        // “+-2”情况, else if...
        else if (str[start] == '-') {                                   
            start++;
            flag = 1;
        }
        //一开始就出现非法字符
        if (str[start] < '0' || str[start] > '9') {                     
            return 0;
        }
        //+-号处理完毕后开始多余0的处理
        while (str[start] == '0') {                                     
            start++;
        }
        for (int i = start; i < str.size(); ++i) {
            //后续可以有多余数字
            if (str[i] < '0' || str[i] > '9') {                         
                return (flag == 0) ? result : -result; 
            }
            int temp = str[i] - '0';
            //用这种方式，不要用pow(x,y)
            result = result * 10 + temp;
            //溢出的处理
            if (result > 0x7FFFFFFF ) {                                 
                return  (flag == 0) ? 0x7FFFFFFF : 0x80000000;
            }
        }
        if (flag == 0) {
            return result;   
        }
        else {
            return -result;
        }

    }
};