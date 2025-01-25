class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<deque<int>> groups;
        int curGroup = -1;
        unordered_map<int, int> num2group;

        vector<int> tmp = nums;
        sort(tmp.begin(), tmp.end());

        for (int n : tmp) {
            if (curGroup == -1 || abs(n - groups[curGroup].back()) > limit) {
                curGroup++;
                groups.push_back(deque<int>());
            }

            groups[curGroup].push_back(n);
            num2group[n] = curGroup;
        }

        vector<int> res;

        for (int n : nums) {
            int gIdx = num2group[n];
            res.push_back(groups[gIdx].front());
            groups[gIdx].pop_front();
        }

        return res;
    }
};