//Solution1
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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end(),cmp);
        result = merge(intervals);
        return result;
    }
};
//Solution2
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
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        if (intervals.size() == 0) {
            result.push_back(newInterval);
            return result;
        }
        int i = 0;
        while (i < intervals.size() && intervals[i].end < newInterval.start) {
            result.push_back(intervals[i++]);
        }
        int left = 0;
        if (i == intervals.size()) {  
            left = newInterval.start;                   
        }
        else {
            left = min(newInterval.start,intervals[i].start);
        }
        while (i < intervals.size() && intervals[i].start <= newInterval.end) {
            i++;
        }
        int right = 0;
        if (i >= 1) {
            right = max(newInterval.end, intervals[i - 1].end);
        }
        else {
            right = newInterval.end;
        }
        result.push_back(Interval(left,right));
        while (i < intervals.size() ) {
            result.push_back(intervals[i++]);
        }
        return result;
    }
};