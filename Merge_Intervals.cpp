# number : 56

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
bool cmp(Interval a, Interval b) {
        return a.start < b.start;
    }
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> result;
        int length = intervals.size();
        for (int i = 0; i < length; i++)
        {
            int start = intervals[i].start;
            int end = intervals[i].end;
            bool flag = false;
            for (int j = 0; j < result.size(); j++)
            {
                if (start <= result[j].end && 
                    end >= result[j].start)
                {
                    result[j].end = end <= result[j].end ? result[j].end : end;
                    result[j].start = start >= result[j].start ? result[j].start : start;
                    flag = true;
                    break;
                }
            }
            if (!flag)
            {
                Interval interval(start, end);
                result.push_back(interval);
            }
        }
        return result;
    }
};
