class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<long long> topSuffix(n + 1, 0);
        vector<long long> bottomPrefix(n + 1, 0);

        for (int j = n - 1; j >= 0; j--) {
            topSuffix[j] = grid[0][j] + topSuffix[j + 1];
        }

        for (int j = 1; j <= n; j++) {
            bottomPrefix[j] = grid[1][j - 1] + bottomPrefix[j - 1];
        }

        long long ret = LLONG_MAX;

        for (int j = 0; j < n; j++) {
            long long secondRobotScore = max(bottomPrefix[j], topSuffix[j + 1]);
            ret = min(ret, secondRobotScore);
        }

        return ret;
    }
};