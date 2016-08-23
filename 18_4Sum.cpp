class Solution {
private:
    vector<vector<int>> threeSum(vector<int>& nums, int target) {
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
                if ( nums[i] + nums[start] + nums[end] == target ) {
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
                else if (nums[i] +  nums[start] + nums[end] > target ) {
                    end--;
                }
                else {
                    start++;
                }
            }
        }
        return v;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> v;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            vector<int> temp(nums.begin() + i + 1, nums.end());
            vector<vector<int>> result = threeSum(temp, target - nums[i]);
            for (int j = 0; j < result.size(); ++j) {
                result[j].push_back(nums[i]);
                v.push_back(result[j]);
            }
        }
        return v;
    }
};