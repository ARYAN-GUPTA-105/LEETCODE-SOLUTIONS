#include <bits/stdc++.h>
using namespace std;

#define ll long long
using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
#define um unordered_map
#define us unordered_set
class Solution {
public:
    ll mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.length();
        vll dp(n + 1, 0);
        vll last(26, 0);
        f(i, 1, n + 1) {
            int c = s[i - 1] - 'a';
            dp[i] = (2LL * dp[i - 1] + 1) % mod;
            dp[i] = (dp[i] - last[c] + mod) % mod;
            last[c] = (dp[i - 1] + 1) % mod;
        }
        return dp[n];
    }
};