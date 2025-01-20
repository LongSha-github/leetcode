class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        int mustJump = 0;
        int canReach = 0;
        int i = 0;
        int ret = 0;

        while (i < n - 1) {
            canReach = max(canReach, i + nums[i]);
            if (i == mustJump) {
                ret++;
                mustJump = canReach;
            }

            i++;
        }

        return ret;
    }
};