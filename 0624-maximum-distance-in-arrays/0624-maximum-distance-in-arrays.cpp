class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        
        int mini = arrays[0][0];
        int maxi = arrays[0][arrays[0].size()-1];
        int res = -1;
        for(int i=1;i<arrays.size();i++){
            res = max(res, max(abs(arrays[i][arrays[i].size()-1] - mini) , abs(maxi - arrays[i][0])));
            mini = min(mini,arrays[i][0]);
            maxi = max(maxi,arrays[i][arrays[i].size()-1]);
        }

        return res;
    }
};