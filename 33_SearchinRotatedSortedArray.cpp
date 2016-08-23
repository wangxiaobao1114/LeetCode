class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0, end = nums.size() - 1;
        if (nums[0] == target) {
            return 0;
        }
        while (start + 1 < end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if ( (target > nums[0] && (nums[mid] < target && nums[mid] > nums[0] ))
                    || (target < nums[0] && (nums[mid] < target || nums[mid] > nums[0])) ) {
                start = mid;
            }
            else {
                end = mid;
            }
        }
        if (nums[start] == target) {
            return start;
        }
        if (nums[end] == target) {
            return end;
        }
        return -1;
    }
};