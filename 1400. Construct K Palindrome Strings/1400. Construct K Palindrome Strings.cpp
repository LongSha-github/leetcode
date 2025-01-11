class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false;

        int hash[26] = {0};

        for (auto& c : s) {
            hash[c - 'a']++;
        }

        int countOdd = 0;

        for (int& n : hash) {
            if (n % 2) countOdd++;
        }


        return countOdd <= k;
    }
};