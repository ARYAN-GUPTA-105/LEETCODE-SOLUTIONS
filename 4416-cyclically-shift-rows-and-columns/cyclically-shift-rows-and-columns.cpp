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
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid,
                                    vector<int>& rs, vector<int>& cs) {
        vvii ans(n, vi(n));
        f(i, 0, rs.size()) {
            vi curr(n);
            f(j, 0, n) { curr[(j - rs[i] + n) % n] = grid[i][j]; }
            grid[i] = curr;
        }
        f(i, 0, cs.size()) {
            vi curr(n);
            f(j, 0, n) { curr[(j - cs[i] + n) % n] = grid[j][i]; }
            f(j, 0, n) { grid[j][i] = curr[j]; }
        }
        return grid;
    }
};