/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
#include<algorithm>
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        if(intervals.size() == 0){
            return intervals;
        }
        /*for(vector<Interval>::iterator iter = intervals.begin()+1;iter != intervals.end();){
            if(iter->end <= (iter-1)->end){
                intervals.erase(iter);
            }
            else if(iter->start <= (iter-1)->end){
                (iter-1)->end = iter->end;
                intervals.erase(iter);
            }
            else{
                iter++;
            }
        }*/
        vector<Interval> ret;
        ret.push_back(intervals[0]);
        for(int i = 1;i < intervals.size();i++){
            if(intervals[i].end <= ret[ret.size()-1].end){
                //skip
            }
            else if(intervals[i].start <= ret[ret.size()-1].end){
                ret[ret.size()-1].end = intervals[i].end;
            }
            else{
                ret.push_back(intervals[i]);
            }
        }
        return ret;
    }
    
    static bool cmp(Interval v1, Interval v2){
        if(v1.start < v2.start)
            return true;
        else if(v1.start > v2.start)
            return false;
        else
            return v1.end < v2.end;
    }
};
