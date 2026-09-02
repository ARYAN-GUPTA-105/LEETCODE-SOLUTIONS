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
    ll helper(string& s) {
        unordered_map<ll, ll> mp;
        ll f1 = 0, f0 = 0, one = 0, zero = 0, ans = 0;
        ll n = s.size();
        mp[0] = -1;
        for (char ch : s) {
            if (ch == '1')
                f1++;
            else
                f0++;
        }
        f(i, 0, n) {
            if (s[i] == '1')
                one++;
            else
                zero++;
            ll diff = one - zero;
            if (mp.count(diff + 2)) {
                ll sz = i - mp[diff + 2];
                if (f1 >= sz / 2 && f0 >= sz / 2)
                    ans = max(ans, sz);
            }
            if (mp.count(diff - 2)) {
                ll sz = i - mp[diff - 2];
                if (f1 >= sz / 2 && f0 >= sz / 2)
                    ans = max(ans, sz);
            }
            if (mp.count(diff)) {
                ll sz = i - mp[diff];
                ans = max(ans, sz);
            }
            if (!mp.count(diff))
                mp[diff] = i;
        }
        return ans;
    }
    int longestBalanced(string s) {
        ll ans = 0;
        ans = max(ans, helper(s));
        reverse(s.begin(), s.end());
        ans = max(ans, helper(s));
        return ans;
    }
};