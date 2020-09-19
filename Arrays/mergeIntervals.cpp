/*
Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

Input: intervals = [[1,3],[0,0],[2,6],[15,18]]
Output: [[0,0],[1,6],[15,18]]

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
      sort(intervals.begin(), intervals.end());
        vector<vector<int>> res;
        
        for (auto interval : intervals) {
            if (res.empty() || (res.back()[1] < interval[0])) {
                // make new entry
                res.push_back({interval[0], interval[1]});
            }
            else {
                // update upper limit
                res.back()[1] = max(res.back()[1], interval[1]);
            }
        }
        
        return res;
    }
};
