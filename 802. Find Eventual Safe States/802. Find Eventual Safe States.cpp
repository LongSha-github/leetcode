class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<int> ret;
        vector<int> color(sz); // 0:while, 1:gray, 2:black

        for (int i = 0; i < sz; i++) {
            if (helper(graph, color, i)) ret.push_back(i);
        }

        return ret;
    }

    bool helper(vector<vector<int>>& graph, vector<int>& color, int i) {
        if (color[i] > 0) return color[i] == 2;
        color[i] = 1;

        for (int j = 0; j < graph[i].size(); j++) {
            if (color[graph[i][j]] == 2) continue;
            if (color[graph[i][j]] == 1 || !helper(graph, color, graph[i][j])) return false;
        }

        color[i] = 2;
        return true;
    }
};