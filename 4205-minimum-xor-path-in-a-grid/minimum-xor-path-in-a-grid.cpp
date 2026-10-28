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
    ll helper(ll i, ll j, ll x, vvii& grid, vector<vvii>& dp) {
        ll n = grid.size(), m = grid[0].size();
        if (i >= n || j >= m) return INT_MAX;
        x ^= grid[i][j];
        if (i == n - 1 && j == m - 1) return x;
        if (dp[i][j][x] != -1) return dp[i][j][x];
        ll r = helper(i, j + 1, x, grid, dp), d = helper(i + 1, j, x, grid, dp);
        return dp[i][j][x] = min(r, d);
    }
    int minCost(vector<vector<int>>& grid) {
        ll n = grid.size(), m = grid[0].size();
        vector<vvii> dp(n, vvii(m, vi(1024, -1)));
        return helper(0, 0, 0, grid, dp);
    }
};