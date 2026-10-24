// tantar mantar
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
#define pob pop_back
class Solution {
public:
    int minCut(string s) {
        ll n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        f(i, 0, n) t[i][i] = true;
        f(l, 2, n + 1) {
            f(i, 0, n - l + 1) {
                ll j = i + l - 1;
                if (l == 2) t[i][j] = (s[i] == s[j]);
                else t[i][j] = ((s[i] == s[j]) && t[i + 1][j - 1]);
            }
        }
        vll dp(n);
        f(i, 0, n) {
            if (t[0][i] == true) dp[i] = 0;
            else {
                dp[i] = INT_MAX;
                f(k, 0, i) if (t[k + 1][i] == true && dp[k] + 1 < dp[i]) dp[i] = 1 + dp[k];
            }
        }
        return dp[n - 1];
    }
};