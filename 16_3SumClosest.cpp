class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int diff = 0x7FFFFFFF;
        for (int i = 0; i < nums.size() - 2; ++i) {
            int start = i + 1, end = nums.size() - 1;
            while (start < end) {
                int curSum = nums[i] + nums[start] + nums[end];
                if (curSum - target == 0) {
                    return target;
                }
                else if (curSum - target > 0) {
                    if (curSum- target < abs(diff) ) {
                        diff = curSum - target;
                    }
                    end--;
                }
                else {
                    if (target - curSum < abs(diff)) {
                        diff = curSum - target;
                    }
                    start++;
                }
            }
        }
        return diff + target;
    }
};