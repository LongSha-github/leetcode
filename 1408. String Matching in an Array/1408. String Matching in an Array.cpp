class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        set<string> resultSet;
        int sz = words.size();

        for (int i = 0; i < sz - 1; i++) {
            for (int j = i + 1; j < sz; j++) {
                check(words, resultSet, i, j);
            }
        }

        return vector<string>(resultSet.begin(), resultSet.end());
    }

    void check(vector<string>& words, set<string>& resultSet, int i, int j) {
        if (words[j].size() > words[i].size()) {
            swap(i, j);
        }

        if (words[i].find(words[j]) != string::npos) {
            resultSet.insert(words[j]);
        }
    }
};