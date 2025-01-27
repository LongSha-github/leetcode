class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<int> indegree(numCourses, 0);
        vector<unordered_set<int>> adj(numCourses);
        vector<unordered_set<int>> preSet(numCourses);

        for (auto& edge : prerequisites) {
            adj[edge[0]].insert(edge[1]);
            indegree[edge[1]]++;
        }

        queue<int> q;

        for (int i = 0; i < numCourses; i++) {
            preSet[i].insert(i);
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (auto& nxt : adj[cur]) {
                for (auto& x : preSet[cur]) {
                    preSet[nxt].insert(x);
                }
                
                indegree[nxt]--;
                if (indegree[nxt] == 0) {
                    q.push(nxt);
                }
            }
        }

        vector<bool> res;

        for (auto& querie : queries) {
            res.push_back(preSet[querie[1]].find(querie[0]) != preSet[querie[1]].end());
        }

        return res;
    }
};