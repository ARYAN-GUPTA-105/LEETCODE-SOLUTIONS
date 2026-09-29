//tantra mantra thoda sa 
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
    bool hasValidPath(vector<vector<char>>& grid) {
        ll m = grid.size(), n = grid[0].size();
        if (!(m + n) & 1 || grid[0][0] & 1 || !grid.back().back() & 1)
            return 0;
        vector<bitset<105>> dp(n + 1);
        dp[1].set(0);
        f(i, 0, m) f(j, 0, n) dp[j + 1] = ((dp[j + 1] | dp[j]) << 1) >> ((grid[i][j] & 1) << 1);
        return dp[n].test(0);
    }
};