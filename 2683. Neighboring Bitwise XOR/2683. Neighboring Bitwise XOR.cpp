class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int count = 0;

        for (auto& d : derived) {
            count += d;
        }

        return count % 2 == 0;
    }
};