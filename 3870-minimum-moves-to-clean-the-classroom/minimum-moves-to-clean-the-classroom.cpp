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
class Solution {
public:
    int minMoves(vector<string>& cl, int eg) {
        ll m = cl.size(), n = cl[0].size(), sr = -1, sc = -1;
        vector<pair<ll, ll>> lt;
        vvii lid(m, vi(n, -1));
        f(r, 0, m) {
            f(c, 0, n) {
                if (cl[r][c] == 'S')
                    sr = r, sc = c;
                else if (cl[r][c] == 'L') {
                    lid[r][c] = lt.size();
                    lt.pb({r, c});
                }
            }
        }
        ll nlt = lt.size();
        if (nlt == 0)
            return 0;
        ll tmask = (1 << nlt) - 1;
        vector<vvii> mxeg(m, vvii(n, vi(1 << nlt, -1)));
        struct State {
            ll r, c, mask, eg;
        };
        queue<State> q;
        q.push({sr, sc, 0, eg});
        mxeg[sr][sc][0] = eg;
        ll moves = 0, dr[] = {-1, 1, 0, 0}, dc[] = {0, 0, -1, 1};
        while (!q.empty()) {
            ll sz = q.size();
            while (sz--) {
                State curr = q.front();
                q.pop();
                if (curr.mask == tmask)
                    return moves;
                if (curr.eg == 0)
                    continue;
                f(d, 0, 4) {
                    ll nr = curr.r + dr[d], nc = curr.c + dc[d];
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                        continue;
                    if (cl[nr][nc] == 'X')
                        continue;
                    ll nmask = curr.mask;
                    if (cl[nr][nc] == 'L')
                        nmask |= (1 << lid[nr][nc]);
                    ll nxteg = curr.eg - 1;
                    if (cl[nr][nc] == 'R')
                        nxteg = eg;
                    if (nxteg > mxeg[nr][nc][nmask]) {
                        mxeg[nr][nc][nmask] = nxteg;
                        q.push({nr, nc, nmask, nxteg});
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};