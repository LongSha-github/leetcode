class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ret = 0;
        int sz = words.size();
        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                check(words, i, j, ret);
            }
        }

        return ret;
    }

    void check(vector<string>& words, int i, int j, int& ret) {
        int m = words[i].size();
        int n = words[j].size();
        if (m > n) return;

        for (int k = 0; k < m; k++) {
            if (words[i][k] != words[j][k]) return;
        }

        while (m > 0) {
            if (words[i][m - 1] != words[j][n - 1]) return;
            m--;
            n--;
        }

        ret++;
    }
};