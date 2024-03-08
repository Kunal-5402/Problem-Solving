class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {

        unordered_map<int,int> m;
        int max_f = INT_MIN;

        for(auto &num: nums){
            m[num]++;

            max_f = max(max_f, m[num]);
        }

        int count = 0;

        for(auto &it: m){
            if(it.second == max_f)
                count++;
        }

        return count * max_f;
    }
};