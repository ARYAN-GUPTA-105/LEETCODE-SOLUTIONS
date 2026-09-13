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
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        ll n = img1.size();
        vector<pair<ll, ll>> i1, i2;
        f(i, 0, n) {
            f(j, 0, n) {
                if (img1[i][j])
                    i1.pb({i, j});
                if (img2[i][j])
                    i2.pb({i, j});
            }
        }
        vvll cnt(2 * n, vll(2 * n, 0));
        ll ans = 0;
        for (auto& x : i1) {
            for (auto& y : i2) {
                ll i = y.first - x.first + n;
                ll j = y.second - x.second + n;
                cnt[i][j]++;
                ans = max(ans, cnt[i][j]);
            }
        }
        return ans;
    }
};