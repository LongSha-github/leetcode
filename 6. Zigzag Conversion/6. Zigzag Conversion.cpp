class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> tmp(numRows);

        int count = 0;
        int direct = 1;

        for (int i = 0; i < s.size(); i++) {
            tmp[count] += s[i];
            count += direct;

            if (direct == 1) {
                if (count == numRows) {
                    count -= 2;
                    direct = -1;
                }
            } else {
                if (count == -1) {
                    count += 2;
                    direct = 1;
                }
            }
        }

        string ret;
        for (int i = 0; i < tmp.size(); i++) {
            ret += tmp[i];
        }

        return ret;
    }
};
