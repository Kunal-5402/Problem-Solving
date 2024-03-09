class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        for(auto &num: nums1){
            if(binary_search(nums2.begin(),nums2.end(),num))
                return num;
        }

        return -1;
        
    }
};