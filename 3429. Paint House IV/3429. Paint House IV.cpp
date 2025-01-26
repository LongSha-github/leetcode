class Solution {
public:
    long long minCost(int n, vector<vector<int>>& cost) {
        long long memo[n / 2][4][4];
        memset(memo, -1, sizeof(memo));
        
        auto dfs = [&](this auto&& dfs, int i, int pre_j, int pre_k) -> long long {
            if (i < 0) {
                return 0;
            }

            long long& res = memo[i][pre_j][pre_k];
            if (res != -1) return res;

            res = LLONG_MAX;

            for (int j = 0; j < 3; j++) {
                if (j == pre_j) continue;

                for (int k = 0; k < 3; k++) {
                    if (k != pre_k && k != j) {
                        res = min(res, dfs(i - 1, j, k) + cost[i][j] + cost[n - 1 - i][k]);
                    }
                }
            }

            return res;
        };

        return dfs(n / 2 - 1, 3, 3);
    }
};