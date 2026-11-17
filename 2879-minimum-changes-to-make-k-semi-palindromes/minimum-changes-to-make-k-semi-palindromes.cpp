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
    int minimumChanges(string s, int k) {
        ll n = s.length(), ans = 0, j = 0;
        vvii c(n, vi(n, 1e9));
        f(i, 0, n) {
            f(j, i + 1, n) {
                ll l = j - i + 1, b = 1e9;
                f(d, 1, l) {
                    if (l % d != 0)
                        continue;
                    ll curr = 0, m = l / d;
                    f(r, 0, d) {
                        f(t, 0, m / 2) if (s[i + r + t * d] != s[i + r + (m - 1 - t) * d]) curr++;
                    }
                    b = min(b, curr);
                }
                c[i][j] = b;
            }
        }
        vvii dp(n + 2, vi(k + 1, 1e9));
        dp[0][0] = 0;
        f(i, 1, n + 1) {
            f(p, 1, k + 1) {
                f(pr, 0, i - 1) {
                    if (dp[pr][p - 1] != 1e9 && c[pr][i - 1] != 1e9) dp[i][p] = min(dp[i][p], dp[pr][p - 1] + c[pr][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};