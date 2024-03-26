class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)
                mp[nums[i]]++;
        }
        // for(auto it: mp){
        //     cout<<it.first<<" "<<it.second<<endl;
        // }
        for(int i=0;i<mp.size();i++){
            if(mp.find(i+1) == mp.end()){
                // cout<<"entered loop"<<endl;
                return i+1;
            }
        }

        // cout<<mp.size()<<endl;
        return mp.size()+1;
    }
};