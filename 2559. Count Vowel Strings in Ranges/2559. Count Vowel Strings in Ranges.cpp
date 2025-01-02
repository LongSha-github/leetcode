class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int sz = words.size();
        vector<int> prefix(sz, 0);
        
        for (int i = 0; i < sz; i++) {
            prefix[i] = prefix[max(0, i - 1)];
            if (isVowel(words[i].front()) && isVowel(words[i].back())) prefix[i]++;
        }

        vector<int> ret(queries.size(), 0);

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            ret[i] = prefix[r] - (l > 0 ? prefix[l - 1] : 0);
        }

        return ret;
    }

    bool isVowel(const char& c){
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
};