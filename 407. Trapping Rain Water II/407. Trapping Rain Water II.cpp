using Node = pair<int, int>; //height, ID

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();
        int seaLevel = INT_MIN;
        int res = 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // put border to pq
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 || j == 0 || i == m - 1 || j == n - 1) {
                    pq.push({heightMap[i][j], i * n + j});
                    visited[i][j] = true;
                }
            }
        }

        while (!pq.empty()) {
            auto [h, ID] = pq.top();
            pq.pop();
            int x = ID / n;
            int y = ID % n;
            seaLevel = max(seaLevel, h);

            for (int i = 0; i < dir.size(); i++) {
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;

                if (heightMap[nx][ny] < seaLevel) {
                    res += seaLevel - heightMap[nx][ny];
                }

                pq.push({heightMap[nx][ny], nx * n + ny});
            }
        }

        return res;
    }
};