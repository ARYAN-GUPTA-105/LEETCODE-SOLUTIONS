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
    int carFleet(int t, vector<int>& p, vector<int>& s) {
        ll n = s.size();
        vector<pair<ll, ll>> arr;
        f(i, 0, n) arr.pb({p[i], s[i]});
        sort(arr.rbegin(), arr.rend());
        ll ans = 0;
        double slow = 0;
        for (auto& [x, y] : arr) {
            double time = (double)(t - x) / (double)y;
            if (time > slow) {
                ans++;
                slow = time;
            }
        }
        return ans;
    }
};