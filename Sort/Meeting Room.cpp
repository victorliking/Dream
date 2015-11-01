/*
Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.

For example,
Given [[0, 30],[5, 10],[15, 20]],
return false.
*/
class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort(intervals.begin(),intervals.end(),[](Interval a, Interval b){
            return a.start<b.start;
        });
         for(int i =0;i<(int)intervals.size()-1;++i)
            if(intervals[i].end>intervals[i+1].start) return false;
        return true;
    }
};