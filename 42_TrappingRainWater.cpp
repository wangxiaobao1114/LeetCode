//Solution1
class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax[height.size()];
        leftMax[0] = 0;
        for (int i = 1; i < height.size(); ++i) {
            leftMax[i] = max(height[i - 1], leftMax[i - 1]);
        }
        int rightMax[height.size()];
        rightMax[height.size() - 1] = 0;
        for (int i = height.size() - 2; i >= 0; --i) {
            rightMax[i] = max(height[i + 1], rightMax[i + 1]);
        }
        int result = 0;
        for (int i = 0; i < height.size(); ++i) {
            if (min(leftMax[i], rightMax[i]) - height[i] > 0) {
                result += (min(leftMax[i], rightMax[i]) - height[i]);
            }
        }
        return result;
    }
};

//Solution2
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) {
            return 0;
        }
        int left = 0, right = height.size() - 1;
        int leftHeight = height[0], rightHeight = height[height.size() - 1];
        int result = 0;
        while (left < right) {
            if (leftHeight <= rightHeight) {
                left++;
                if (height[left] < leftHeight) {
                    result += (leftHeight - height[left]);
                }
                else {
                    leftHeight = height[left];
                }
            }
            else {
                right--;
                if (height[right] < rightHeight) {
                    result += (rightHeight - height[right]);
                }
                else {
                    rightHeight = height[right];
                }
            }
        }
        return result;
    }
};