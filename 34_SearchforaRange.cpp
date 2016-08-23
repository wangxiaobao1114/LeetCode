class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        if (nums.size() == 0) {
            return result;
        }
        int start = 0, end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] < target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (nums[start] == target) {
            result.push_back(start);
        }
        else if (nums[end] == target) {
            result.push_back(end);
        }
        
        start = 0;
        end = nums.size() - 1;
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] <= target) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (nums[end] == target) {
            result.push_back(end);
        }
        else if (nums[start] == target) {
            result.push_back(start);
        }
        if (result.size() != 0) {
            return result;
        }
        else {
            return vector<int> {-1, -1};
        }
    }
};