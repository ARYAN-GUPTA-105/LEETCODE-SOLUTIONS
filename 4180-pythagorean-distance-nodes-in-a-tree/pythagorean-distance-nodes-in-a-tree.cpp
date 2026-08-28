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
    vll helper(int st, int n, vvll& v) {
        vll d(n, -1);
        d[st] = 0;
        vll q;
        q.reserve(n);
        q.pb(st);
        ll h = 0;
        while (h < q.size()) {
            ll u = q[h++];
            for (ll x : v[u]) {
                if (d[x] == -1)
                    d[x] = d[u] + 1, q.pb(x);
            }
        }
        return d;
    }
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vvll g(n);
        for (auto& e : edges) {
            g[e[0]].pb(e[1]);
            g[e[1]].pb(e[0]);
        }
        vll dx = helper(x, n, g);
        vll dy = helper(y, n, g);
        vll dz = helper(z, n, g);
        ll ans = 0;
        f(i, 0, n) {
            ll a = dx[i], b = dy[i], c = dz[i];
            ll m = max({a, b, c});
            if (a * a + b * b + c * c == 2 * m * m)
                ans++;
        }
        return ans;
    }
};