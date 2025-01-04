class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int sz = s.size();
        int ret = 0;

        for (char c = 'a'; c <= 'z'; c++) {
            int first = -1;
            int last = -1;
            
            for (int i = 0; i < sz; i++) {
                if (s[i] == c) {
                    if (first == -1) {
                        first = i;
                    } else {
                        last = i;
                    }
                }
            }

            if (first != -1 && last != -1 && last - first > 1) {
                unordered_set<char> mid;
                for (int j = first + 1; j < last; j++) {
                    mid.insert(s[j]);
                }

                ret += mid.size();
            }
        }

        return ret;
    }
};