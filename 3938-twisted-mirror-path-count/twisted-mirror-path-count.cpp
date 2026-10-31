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
    ll mat[2][2][2] = {{{1,1},{1,1}},{{0,1},{1,0}}};
    ll mod = 1e9 + 7;
    int uniquePaths(vector<vector<int>>& grid) {
        ll m = grid.size(), n = grid[0].size(), ans = 0;
        vll dp(n,0);dp[0] = 1;
        f(i,0,m){
            ans = 0;
            f(j,0,n){
                ll c = grid[i][j], t = dp[j];
                dp[j] = (ans * mat[c][1][0] + t * mat[c][1][1]) % mod;
                ans = (ans * mat[c][0][0] + t * mat[c][0][1]) % mod;
            }
        }
        return ans;
    }
};