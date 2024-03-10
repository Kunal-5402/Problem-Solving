class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int size = nums1.size()-1;
        m--;
        n--;

        while(m >= 0 and n >= 0){
            if(nums1[m] > nums2[n]){
                nums1[size] = nums1[m];
                m--;
                size--;
            }else{
                nums1[size] = nums2[n];
                n--;
                size--;
            }
        }

        while(m >= 0){
            nums1[size--] = nums1[m--];
        }
        while(n >= 0){
            nums1[size--] = nums2[n--];
        }
    }
};