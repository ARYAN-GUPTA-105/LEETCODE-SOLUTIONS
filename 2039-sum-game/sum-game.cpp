class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();

        int L = 0, R = 0;
        int qL = 0, qR = 0;

        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qL++;
            else
                L += num[i] - '0';
        }

        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                qR++;
            else
                R += num[i] - '0';
        }
        if ((qL + qR) % 2 == 1) return true;

        return (L - R) != ((qR - qL) * 9) / 2;
    }
};