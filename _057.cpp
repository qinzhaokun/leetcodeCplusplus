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
        vector<Interval> ret;bool flag = false;
        for(int i = 0;i < intervals.size();i++){
            if(flag) ret.push_back(intervals[i]);
            else if(newInterval.start <= intervals[i].end){
                if(newInterval.end < intervals[i].start){
                    ret.push_back(newInterval);
                    flag = true;
                    i--;
                }
                else{
                    newInterval.start = min(newInterval.start,intervals[i].start);
                    newInterval.end = max(newInterval.end,intervals[i].end);
                }
            }
            else{
                ret.push_back(intervals[i]);
            }
        }
        if(!flag){
            ret.push_back(newInterval);
        }
        return ret;
    }
};
