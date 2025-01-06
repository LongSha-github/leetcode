class Solution {
public:
    vector<int> minOperations(string boxes) {
        int sz = boxes.size();
        vector<int> leftOperations(sz, 0);
        vector<int> rightOperations(sz, 0);
        
        int count = 0;
        int operations = 0;

        for (int i = 0; i < sz; i++) {
            leftOperations[i] = operations;
            count += (boxes[i] == '1') ? 1 : 0;
            operations += count;
        }
        
        count = 0;
        operations = 0;

        for (int i = sz - 1; i >= 0; i--) {
            rightOperations[i] = operations;
            count += (boxes[i] == '1') ? 1 : 0;
            operations += count;
        }
        
        vector<int> result(sz, 0);
        for (int i = 0; i < sz; i++) {
            result[i] = leftOperations[i] + rightOperations[i];
        }
        
        return result;
    }
};
