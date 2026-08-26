class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int sum = a ^ b;
            int c = (a & b) << 1;
            a = sum;
            b = c;
        }
        return a;
    }
};