//Solution1
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        if (nums.size() < 3) {
            return v;
        }
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i >= 1 && nums[i] == nums[i - 1]) {  //遇到相同的选定跳过
                continue;
            } 
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                if ( nums[i] + nums[start] + nums[end] == 0 ) {
                    if (start > i + 1 && nums[start] == nums[start - 1]) { //[0,0,0,0]情况， 相同的相加元素
                        start++;
                        continue;
                    }
                    vector<int> temp{nums[i], nums[start], nums[end]};
                    v.push_back(temp);
                    start++;
                }
                else if (nums[i] + nums[start] + nums[end] > 0 ) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return v;
    }
};
//Solution2
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        if (nums.size() < 3) {  //数组元素个数过少，直接返回
            return v;
        }
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i >= 1 && nums[i] == nums[i - 1]) {
                continue;
            } 
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                if ( nums[i] + nums[start] + nums[end] == 0 ) {
                    vector<int> temp{nums[i], nums[start], nums[end]};
                    v.push_back(temp);
                    start++;
                    end--;
                    while ( (start < end) && nums[start] == nums[start - 1]) { //没加start < end虽然过了，估计是样例不够完善
                        start++;
                    }
                    while ( (start < end) && nums[end] == nums[end + 1]) {
                        end--;
                    }
                }
                else if (nums[i] +  nums[start] + nums[end] > 0 ) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return v;
    }
};
