class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> hash;
        vector<int> ret(A.size(), 0);

        int sum = 0;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] == B[i]) {
                sum++;
            } else {
                hash[A[i]]++;
                if (hash[A[i]] == 2) sum++;
                hash[B[i]]++;
                if (hash[B[i]] == 2) sum++;
            }

            ret[i] = sum;
        }

        return ret;
    }
};