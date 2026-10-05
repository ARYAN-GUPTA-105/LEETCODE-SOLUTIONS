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
    ll helper(ll x, ll y) {
        ll ans = (x - y + 10) % 10;
        return min(ans, 10 - ans);
    }
    int minRotations(int n, string s) {
        ll l = s[s.length() - 1] - '0', p = 0, b = 0, a = INT_MIN;
        for (char ch : s) {
            ll curr = ch - '0';
            a = max(a, helper(p, curr) - helper(p, l));
            b += helper(p, curr);
            p = curr;
        }
        return b - a;
    }
};