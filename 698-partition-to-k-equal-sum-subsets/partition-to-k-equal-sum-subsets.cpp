
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if (total % k != 0)
            return false;

        sort(nums.rbegin(), nums.rend());
        int target = total / k;

        vector<int> visited(n, false);

        function<bool(int, int, int)> dfs = [&](int i, int sum, int k) {
            if (k == 1)
                return true;

            if (i >= n)
                return false;

            if (sum == target)
                return dfs(0, 0, k - 1);

            for (int j = i; j < n; j++) {
                
                if (visited[j] or sum + nums[j] > target) {
                    continue;
                }

                visited[j] = true;

                if (dfs(j + 1, sum + nums[j], k)) {
                    return true;
                }

                visited[j] = false;
            }
            return false;
        };

        return dfs(0, 0, k);
    }
};