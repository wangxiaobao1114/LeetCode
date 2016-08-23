//Solution1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> v(nums);
        vector<int> result;
        sort(nums.begin(), nums.end());
        int i = 0,j = nums.size() - 1;
        while (nums[i] + nums[j] != target) {
            if (nums[i] + nums[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
        for (int k = 0; k < nums.size(); ++k) {
            if (v[k] == nums[i]) {
                result.push_back(k);
                break;
            }
        }
        for (int k = nums.size() - 1; k >=  0; --k) { //从后向前扫描
           if (v[k] == nums[j]) {
                result.push_back(k);
                break;
            }
        }
        return result;
    }
};

//Solution2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //数值 与 下标一一对应
        unordered_map<int,int> hash;
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i){
            if (hash.find(target - nums[i]) != hash.end()) {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            hash[nums[i]] = i;
        }
        return result;
    }
};