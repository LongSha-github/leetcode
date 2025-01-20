class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        unordered_map<int, int> hash; // num, ID
        vector<int> row(m, 0);
        vector<int> col(n, 0);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                hash[mat[i][j]] = i * n + j;
            }
        }

        int x = 0;
        int y = 0;

        for (int i = 0; i < arr.size(); i++) {
            x = hash[arr[i]] / n;
            y = hash[arr[i]] % n;

            if (++row[x] == n) return i;
            if (++col[y] == m) return i;
            
        }

        return -1;
    }
};