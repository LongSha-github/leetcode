class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ret = 0;
        int psz = pref.size();

        for (int i = 0; i < words.size(); i++) {
            if (psz > words[i].size()) continue;
            if (words[i].substr(0, psz) == pref) ret++;
        }

        return ret;
    }
};