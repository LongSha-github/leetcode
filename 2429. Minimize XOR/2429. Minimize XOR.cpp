class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits1 = countBits(num1);
        int bits2 = countBits(num2);
        int ret = num1;

        if (bits1 == bits2) {
            return num1;
        } else if (bits1 < bits2) {
            int remain = bits2 - bits1;
            for (int i = 0; i < 31; i++) {
                if (remain == 0) break;
                if ((num1 & (1 << i)) == 0) {
                    remain--;
                    ret |= (1 << i);
                }
            }
        } else {
            int remain = bits1 - bits2;
            for (int i = 0; i < 31; i++) {
                if (remain == 0) break;
                if ((ret & (1 << i)) != 0) {
                    remain--;
                    ret &= ~(1 << i); // Clear bit
                }
            }
        }

        return ret;
    }

    int countBits(int n) {
        int sum = 0;

        while (n) {
            n &= (n - 1);
            sum++;
        }

        return sum;
    }
};