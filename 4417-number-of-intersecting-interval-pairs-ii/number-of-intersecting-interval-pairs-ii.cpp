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
    long long countIntersectingIntervals(vector<vector<int>>& it) {
        ll n = it.size();
        vll st, ed;
        f(i, 0, n) {
            st.pb(it[i][0]);
            ed.pb(it[i][1]);
        }
        sort(st.begin(), st.end());
        sort(ed.begin(), ed.end());
        ll ans = 0, j = 0;
        f(i, 0, n) {
            while (j < n && ed[j] < st[i])
                j++;
            ans += i - j;
        }
        return ans;
    }
};