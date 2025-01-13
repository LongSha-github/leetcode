class Solution {
public:
    int minimumLength(string s) {
        int hash[26] = {0};

        for (auto& c : s) {
            hash[c - 'a']++;
        }

        int ret = 0;

        for (int i = 0; i < 26; i++) {
            while (hash[i] >= 3) {
                hash[i] = (hash[i] / 3) + (hash[i] % 3);
            }

            ret += hash[i];
        }

        return ret;
    }
};