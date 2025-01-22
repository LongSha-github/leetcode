using Node = pair<int, int>; // (x, y)

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> dir{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<Node> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isWater[i][j] == 1) {
                    isWater[i][j] = 0; 
                    q.push({i, j});
                } else {
                    isWater[i][j] = -1; 
                }
            }
        }

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (const auto& d : dir) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || isWater[nx][ny] != -1) continue;

                isWater[nx][ny] = isWater[x][y] + 1;

                q.push({nx, ny});
            }
        }

        return isWater;
    }
};
