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
    pair<ll, ll> helper(ll n, ll fp, ll sp) {
        ll e = INT_MAX, l = INT_MIN;
        if (fp == n - sp + 1)
            return {1, 1};
        if (fp > sp)
            swap(fp, sp);
        if (n <= 4)
            return {2, 2};
        ll mid = (n + 1) / 2;
        if (fp + sp > n + 1) {
            ll x = n + 1 - fp;
            fp = n + 1 - sp;
            sp = x;
        }
        if (sp * 2 <= n + 1) {
            ll x = fp - 1, y = sp - fp - 1;
            f(i, 0, x + 1) {
                f(j, 0, y + 1) {
                    auto [a, b] = helper(mid, i + 1, i + j + 2);
                    e = min(e, a + 1);
                    l = max(l, b + 1);
                }
            }
        } else {
            ll x = n + 1 - sp, a = fp - 1, b = x - fp - 1, c = sp - x - 1;
            f(i, 0, a + 1) {
                f(j, 0, b + 1) {
                    ll nx = i + j + 1 + (c + 1) / 2 + 1;
                    auto [k, m] = helper(mid, i + 1, nx);
                    e = min(e, k + 1);
                    l = max(l, m + 1);
                }
            }
        }
        return {e, l};
    }
    vector<int> earliestAndLatest(int n, int fp, int sp) {
        auto [ans1, ans2] = helper(n, fp, sp);
        return {(int)ans1, (int)ans2};
    }
};