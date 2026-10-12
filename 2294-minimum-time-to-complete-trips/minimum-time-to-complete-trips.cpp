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
    bool helper(vi& t, ll mid, ll tt) {
        ll cnt = 0;
        f(i, 0, t.size()) { cnt += (mid / t[i]); }
        return (cnt < tt) ? false : true;
    }
    long long minimumTime(vector<int>& time, int t) {
        t = (ll)t;
        ll n = time.size();
        sort(time.begin(), time.end());
        ll st = 1, ed = 1ll * time[0] * t, ans = ed;
        while (st <= ed) {
            ll mid = st + (ed - st) / 2;
            if (helper(time, mid, t)) {
                ans = mid;
                ed = mid - 1;
            } else
                st = mid + 1;
        }
        return ans;
    }
};