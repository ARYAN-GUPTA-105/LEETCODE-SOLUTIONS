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
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    int minCost(vector<vector<int>>& grid) {
        ll m = grid.size(), n = grid[0].size();
        vvll v(m, vll(n, INT_MAX));
        deque<pair<ll, ll>> dq;
        dq.emplace_front(0, 0);
        v[0][0] = 0;
        while (!dq.empty()) {
            auto [x, y] = dq.front(); dq.pop_front();
            f(i, 0, 4) {
                ll nx = x + dx[i], ny = y + dy[i];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    ll c = (i + 1 == grid[x][y]) ? 0 : 1;
                    if (v[x][y] + c < v[nx][ny]) {
                        v[nx][ny] = v[x][y] + c;
                        if (c == 0) dq.emplace_front(nx, ny);
                        else dq.emplace_back(nx, ny);
                    }
                }
            }
        }
        return v[m - 1][n - 1];
    }
};