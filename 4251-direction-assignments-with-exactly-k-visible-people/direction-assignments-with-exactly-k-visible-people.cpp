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
    ll mod = 1e9 + 7;
    ll helper(ll b, ll e) {
        ll ans = 1;
        b %= mod;
        while (e > 0) {
            if (e % 2)
                ans = (ans * b) % mod;
            b = (b * b) % mod;
            e /= 2;
        }
        return ans;
    }
    ll helper2(ll n) { return helper(n, mod - 2); }
    ll helper3(ll n, ll k) {
        if (k < 0 || k > n)
            return 0;
        if (k == 0 || k == n)
            return 1;
        if (k > n / 2)
            k = n - k;
        ll m = 1, d = 1;
        f(i, 0, k) {
            m = (m * (n - i)) % mod;
            d = (d * (i + 1)) % mod;
        }
        return (m * helper2(d)) % mod;
    }
    int countVisiblePeople(int n, int pos, int k) {
        return (helper3(n - 1, k) * 2) % mod;
    }
};