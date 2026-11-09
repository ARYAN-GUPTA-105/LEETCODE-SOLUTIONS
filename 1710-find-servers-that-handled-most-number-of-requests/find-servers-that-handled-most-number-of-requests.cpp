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
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<ll> st;
        f(i, 0, k) st.insert(i);
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<>> b;
        vll cnt(k);
        ll n = arrival.size();
        f(i, 0, n) {
            ll t = arrival[i];
            while (!b.empty() && b.top().first <= t) st.insert(b.top().second), b.pop();
            if (st.empty()) continue;
            ll p = i % k;
            auto it = st.lower_bound(p);
            if (it == st.end()) it = st.begin();
            ll s = *it; st.erase(it); cnt[s]++;
            b.emplace(t + load[i], s);
        }
        ll mx = *max_element(cnt.begin(), cnt.end());
        vi ans;
        f(i, 0, k) if (cnt[i] == mx) ans.pb(i);
        return ans;
    }
};