class Solution {
public:
    int minFlips(string s) {
        int n = s.length();
        if(n < 3) return 0;
        int cnt = 0;
        for(char ch : s) (ch == '0' ? cnt++ : cnt);
        int cnt1 = n - cnt;
        int a = cnt, b = max(cnt1 - 1, 0), c = cnt1 - (s[0] - '0') - (s[n-1] - '0');
        return min({a,b,c});
    }
};