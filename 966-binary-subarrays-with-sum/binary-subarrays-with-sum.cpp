class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        auto atmostK = [&](int k){
            int s = 0;
            int e = 0;
            int sum = 0;
            int count = 0;

            while (e < nums.size()) {
                sum += nums[e];

                while (s <= e and sum > k) {
                    sum -= nums[s];
                    s++;
                }
                count += (e - s + 1);
                e++;
            }

            return count;
        };

        return atmostK(goal) - atmostK(goal-1);
    }
};