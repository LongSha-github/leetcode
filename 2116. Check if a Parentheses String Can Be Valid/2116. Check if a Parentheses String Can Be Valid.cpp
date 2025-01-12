class Solution {
public:
    bool canBeValid(string s, string locked) {
        int sz = s.size();
        if (sz % 2 != 0) return false;

        int countL = 0;

        for (int i = 0; i < sz; i++) {
            if (locked[i] == '0') {
                countL++;
            } else {
                if (s[i] == ')') {
                    countL--;
                    if (countL < 0) return false;
                } else {
                    countL++;
                }
            }
        }

        int countR = 0;

        for (int i = sz - 1; i >= 0; i--) {
            if (locked[i] == '0') {
                countR++;
            } else {
                if (s[i] == '(') {
                    countR--;
                    if (countR < 0) return false;
                } else {
                    countR++;
                }
            }
        }

        return true;
    }
};