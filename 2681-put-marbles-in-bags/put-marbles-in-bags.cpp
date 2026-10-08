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
    long long putMarbles(vector<int>& w, int k) {
        ll n = w.size();
        k = (ll)k;
        if (k == 1 || k == n) return 0;
        vll c;
        f(i, 0, n - 1) c.pb(w[i] + w[i + 1]);
        sort(c.begin(), c.end());
        ll mn = 0, mx = 0;
        f(i, 0, k - 1) mn += c[i], mx += c[n - 2 - i];
        return mx - mn;
    }
};