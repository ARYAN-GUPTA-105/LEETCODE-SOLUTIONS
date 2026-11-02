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
#define pob pop_back
class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        ll n = pt.size();
        vector<pair<ll,ll>> v(n);
        f(i,0,n) v[i].first = -gt[i], v[i].second = pt[i];
        sort(v.begin(),v.end());
        ll ans = 0, curr = 0;
        f(i,0,n) ans = max(ans,curr + v[i].second - v[i].first), curr += v[i].second;
        return ans;
    }
};