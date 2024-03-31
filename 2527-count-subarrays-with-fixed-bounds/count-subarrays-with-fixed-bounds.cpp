class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int s = 0;
        int e = 0;
        int n = nums.size();
        long long count = 0;
        int maxi = -1;
        int mini = -1;

        while(e < n){

            if(nums[e] >= minK and nums[e] <= maxK){
                if(nums[e] == minK)
                    mini = e;
                if(nums[e] == maxK)
                    maxi = e;
            }
            else{
                mini = -1;
                maxi = -1;
                s = e + 1;
            }

            count += max(0, min(mini, maxi) - s + 1);
            e++;
        }
        return count;
    }
};