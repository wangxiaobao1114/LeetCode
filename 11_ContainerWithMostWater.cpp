//Solution1
class Solution {
public:
    int maxArea(vector<int>& height) {
        set<int> s;
        for (int i = 0; i < height.size(); ++i) {
            s.insert(height[i]);
        }
        auto itr = s.begin();
        int result = 0;
        int left = 0, right = height.size() - 1;  //这句优化！
        for (itr = s.begin(); itr != s.end(); ++itr) {
             while (height[left] < (*itr) ) {
                 ++left;
             }
             while (height[right] < (*itr) ) {
                 --right;
             }
             result = max(result, (right - left) * (*itr) );
        }
        return result;
    }
};

//Solution2
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1, result = 0;
        while (i < j) {
            int minHeight = min(height[i], height[j]);
            result = max(result, minHeight * (j - i));
            while (height[i] <= minHeight) {
                i++;
            }
            while (height[j] <= minHeight) {
                j--;
            }
        }
        return result;
    }
};