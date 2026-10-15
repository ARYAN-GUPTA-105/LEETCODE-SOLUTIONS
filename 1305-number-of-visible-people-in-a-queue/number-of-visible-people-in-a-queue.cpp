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
#define pob pop_back
#define um unordered_map
#define us unordered_set
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        ll n = h.size();
        vi ans(n), q;
        f(i, 0, n) {
            while (!q.empty() && h[q.back()] <= h[i]) ans[q.back()]++, q.pob();
            if (!q.empty()) ans[q.back()]++;
            q.pb(i);
        }
        return ans;
    }
};