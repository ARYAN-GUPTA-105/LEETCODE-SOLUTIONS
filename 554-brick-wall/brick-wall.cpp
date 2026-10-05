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
    int leastBricks(vector<vector<int>>& wall) {
        ll n = wall.size(), mx = 0;
        um<ll, ll> mp;
        f(i, 0, n) {
            ll pos = 0;
            ll m = wall[i].size();
            f(j, 0, m - 1) {
                ll curr = wall[i][j];
                pos += curr;
                mp[pos]++;
                mx = max(mp[pos], mx);
            }
        }
        return n - mx;
    }
};