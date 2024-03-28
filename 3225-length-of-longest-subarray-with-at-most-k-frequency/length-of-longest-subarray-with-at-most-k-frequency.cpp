class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int s = 0;
        int e = 0;
        unordered_map<int,int> m;
        int ans = 0;

        while(e < nums.size()){
            if(m[nums[e]] <= k){
                m[nums[e]]++;
            }

            while(s < e and m[nums[e]] > k){
                m[nums[s]]--;
                s++;
            }
            
            e++;
            ans = max(ans, e - s);
        }

        return ans;
    }
};