/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    static bool cmp (const Interval& I1, const Interval& I2) {
        return I1.start < I2.start;
    }
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            return result;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int left = intervals[0].start, right = intervals[0].end;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i].start <= right) {
                right = max(right,intervals[i].end);
            }
            else {
                result.push_back(Interval(left,right));
                left = intervals[i].start;
                right = intervals[i].end;
            }
        }
        result.push_back(Interval(left,right));
        return result;
    }
};