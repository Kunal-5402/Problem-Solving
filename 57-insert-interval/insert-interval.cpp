class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int i = 0;

        int x1 = newInterval[0];
        int y1 = newInterval[1];

        vector<vector<int>> ans;

        while(i<n and intervals[i][1] < x1){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i<n and intervals[i][0] <= y1){
            x1 = min(x1,intervals[i][0]);
            y1 = max(y1,intervals[i][1]);
            i++;
        }
        ans.push_back({x1,y1});

        while(i < n){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};