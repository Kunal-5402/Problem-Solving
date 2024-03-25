class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {

        vector<int> ans;
        int i = 0;
        while(i < nums.size()){
            while(nums[i] != nums[nums[i]-1])
                swap(nums[i], nums[nums[i]-1]);
            i++;
        }
        for(int i = 0;i<nums.size();i++){
            if(i != nums[i]-1)
                ans.push_back(nums[i]);
        }
        return ans;
    }
};