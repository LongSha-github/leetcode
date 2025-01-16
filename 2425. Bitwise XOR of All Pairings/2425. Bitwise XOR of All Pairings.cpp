class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int ret = 0;

        if (nums2.size() % 2 == 1) {
            for (auto& n : nums1) {
                ret ^= n;
            }            
        }

        if (nums1.size() % 2 == 1) {
            for (auto& n : nums2) {
                ret ^= n;
            }          
        }

        return ret;
    }
};