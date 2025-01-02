class Solution {
public:
    int maxScore(string s) {
        int sz = s.size();
        vector<int> prefixSumL(sz);
        vector<int> prefixSumR(sz);

        for (int i = 0; i < sz; i++) {
            prefixSumL[i] = prefixSumL[max(0, i - 1)] + (s[i] == '0' ? 1 : 0);
        }

        for (int i = sz - 1; i >= 0; i--) {
            prefixSumR[i] = prefixSumR[min(sz - 1, i + 1)] + (s[i] == '1' ? 1 : 0);
        }

        int ret = 0;

        for (int i = 1; i < sz; i++) {
            ret = max(ret, prefixSumL[i - 1] + prefixSumR[i]);
        }

        return ret;
    }
};