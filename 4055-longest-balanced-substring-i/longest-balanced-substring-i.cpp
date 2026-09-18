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
    int longestBalanced(string s) {
        ll n = s.size();
        ll ans = 0;
        f(i, 0, n) {
            vll cnt(26, 0);
            ll distinct = 0;
            ll mx = 0;
            f(j, i, n) {
                ll x = s[j] - 'a';
                cnt[x]++;
                if (cnt[x] == 1)
                    distinct++;
                mx = max(mx, cnt[x]);
                ll len = j - i + 1;
                if (distinct * mx == len)
                    ans = max(ans, len);
            }
        }
        return ans;
    }
};