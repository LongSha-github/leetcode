class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int maxFreq[26] = {0};

        for (const string& word : words2) {  
            int freq[26] = {0};
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }

        vector<string> result;
        for (const string& word : words1) {
            int freq[26] = {0};
            for (char c : word) {
                freq[c - 'a']++;
            }

            bool isSubset = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isSubset = false;
                    break;
                }
            }

            if (isSubset) {
                result.push_back(word);
            }
        }

        return result;
    }
};
