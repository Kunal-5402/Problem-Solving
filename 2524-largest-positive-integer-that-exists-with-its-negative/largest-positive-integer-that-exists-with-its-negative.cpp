class Solution {
public:
    int findMaxK(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0)
                if(s.count(abs(nums[i])))
                    ans = max(ans, abs(nums[i]));
        }
        return ans;
    }
};