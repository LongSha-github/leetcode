// Dijkstra 經典算法

using Node = tuple<int, int, int>;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(); 
        int n = grid[0].size();

        // four dicrections, right, left, down, up
        vector<pair<int, int>>  directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int startX = 0;
        int startY = 0;
        int endX = m - 1;
        int endY = n - 1;

        vector<vector<int>> costs(m, vector<int>(n, INT_MAX));
        costs[startX][startY] = 0;

        priority_queue<Node, vector<Node>, greater<Node>> pq;
        pq.push({0, startX, startY});

        while (!pq.empty()) {
            auto [currentCost, x, y] = pq.top();
            pq.pop();

            if (x == endX && y == endY) return currentCost;

            for (int i = 0; i < directions.size(); i++) {
                int nx = x + directions[i].first;
                int ny = y + directions[i].second;

                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    int newCost = currentCost;
                    if (grid[x][y] != (i + 1)) {
                        newCost++;
                    }

                    if (newCost < costs[nx][ny]){
                        costs[nx][ny] = newCost;
                        pq.push({newCost, nx, ny});
                    }
                }
            }
        }

        return -1;
    }
};