class Solution {
private:
    vector<vector<int>>result;
    void dfs(int start, int end, const vector<int>& candidates, int target, vector<int>& internal) {
        if (start > end) {
            return;
        }
        if (candidates[start] == target) {
            internal.push_back(candidates[start]);
            result.push_back(internal);
            internal.pop_back();
            return;   
        }
        if (candidates[start] > target) {
            return;
        }
        dfs(start + 1, end, candidates, target, internal);
        internal.push_back(candidates[start]);
        dfs(start, end, candidates, target - candidates[start], internal);
        internal.pop_back();
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        int end = candidates.size() - 1;
        vector<int> internal;
        dfs(0, end, candidates, target, internal);
        return result;
    }
};