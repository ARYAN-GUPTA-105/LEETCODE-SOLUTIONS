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
    bool helper(ll mid, ll n, vi& q, ll sum) {
        if (mid * n < sum)
            return false;
        ll curr = 0;
        f(i, 0, q.size()) {
            if (q[i] % mid == 0) {
                curr += q[i] / mid;
            } else
                curr += (q[i] / mid) + 1;
        }
        return curr <= n;
    }
    int minimizedMaximum(int n, vector<int>& q) {
        ll i = 1, j = 100000, ans = 0, sum = 0, s = q.size();
        f(i, 0, s) sum += q[i];
        while (i <= j) {
            ll mid = i + (j - i) / 2;
            if (helper(mid, n, q, sum)) {
                j = mid - 1;
                ans = mid;
            } else {
                i = mid + 1;
            }
        }
        return ans;
    }
};