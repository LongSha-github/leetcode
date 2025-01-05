class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int sz = s.size();
        vector<int> diff(sz + 1, 0);

        for (int i = 0; i < shifts.size(); i++) {
            int start = shifts[i][0];
            int end = shifts[i][1];
            int direction = (shifts[i][2] == 0 ? -1 : 1);

            diff[start] += direction;
            diff[end + 1] -= direction;
        }

        for (int i = 1; i < sz; i++) {
            diff[i] = diff[i - 1] + diff[i];
        }

        for (int i = 0; i < sz; i++) {
            int shift = (s[i] - 'a' + diff[i]) % 26;
            if (shift < 0) shift += 26;
            s[i] = 'a' + shift;
        }

        return s;
    }
};