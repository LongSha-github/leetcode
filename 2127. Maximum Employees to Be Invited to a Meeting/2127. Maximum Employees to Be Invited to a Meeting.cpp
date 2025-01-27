class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int sz = favorite.size();
        vector<int> indegree(sz, 0);
        vector<bool> visited(sz, false);
        vector<int> depth(sz, 1);

        for (int i = 0; i < sz; i++) {
            indegree[favorite[i]]++;
        }

        queue<int> q;

        for (int i = 0; i < sz; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            visited[cur] = true;
            int nxt = favorite[cur];
            indegree[nxt]--;
            depth[nxt] = depth[cur] + 1;

            if (indegree[nxt] == 0) {
                q.push(nxt);
            }
        }

        int max_multi_node_circle = 0;
        int node_link = 0;

        for (int i = 0; i < sz; i++) {
            if (visited[i]) continue;

            int j = i;
            int count = 0;
            while (!visited[j]) {
                visited[j] = true;
                count++;
                j = favorite[j];
            }

            if (count > 2) {
                max_multi_node_circle = max(max_multi_node_circle, count);
            } else if (count == 2) {
                node_link += depth[i] + depth[favorite[i]];
            }
        }
        
        return max(max_multi_node_circle, node_link);
    }
};