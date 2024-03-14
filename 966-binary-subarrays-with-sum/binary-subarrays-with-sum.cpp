class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        // int s = 0;
        // int e = 0;
        // int sum = 0;
        // int count = 0;

        // while(e < nums.size()){
        //     sum += nums[e];

        //     if(sum == goal)
        //         count++;
            
        //     if(sum > goal){
        //         while(sum > goal){
        //             sum -= nums[s];
        //             s++;
        //         }
        //     }

        //     e++;
        // }

        // return count;
        unordered_map<int,int> map;
        
        int sum = 0, result = 0;
        map[sum] = 1;
        
        for (int n : nums) {
            sum += n;
            result += map[sum - k];
            map[sum]++;
        }
    
        return result;
    }
};