class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        unordered_map<int, int> m;
        m[0] = -1;
        int count;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                count--;
            else
                count++;

            if (m.find(count) != m.end()) {
                ans = max(ans, i - m[count]);
            } 
            else {
                m[count] = i;
            }
        }

        return ans;
    }
};