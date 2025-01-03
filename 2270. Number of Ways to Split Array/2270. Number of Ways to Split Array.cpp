class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int sz = nums.size();
        vector<long> prefix(sz);
        for (int i = 0; i < sz; i++) {
            prefix[i] = prefix[max(0, i - 1)] + nums[i];
        }

        long total = prefix[sz - 1];
        int ret = 0;

        for (int i = 0;i < sz - 1; i++) {
            if(prefix[i] >= total - prefix[i]) ret++;
        }

        return ret;
    }
};