using Node = pair<int, int>;
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ret = 0;
        
        unordered_map<int, int> row(m);
        unordered_map<int, int> col(n);
        vector<Node> servers;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;
                servers.push_back({i, j});
                row[i]++;
                col[j]++;
            }
        }

        for (auto& [i, j] : servers) {
            if (row[i] > 1 || col[j] > 1) ret++;
        }

        return ret;
    }
};