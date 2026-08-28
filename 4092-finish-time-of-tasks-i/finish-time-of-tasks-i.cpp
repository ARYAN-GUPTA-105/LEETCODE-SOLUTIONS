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
class Solution {
public:
    vvll adj;
    vi t;
    ll helper(int node){
        if(adj[node].empty()) return (ll)t[node];
        ll mn = LONG_MAX, mx = 0;
        for(ll v : adj[node]){
            ll x = helper(v);
            mn = min(mn,x);
            mx = max(mx,x);
        }
        return mx + (mx - mn) + (ll)t[node];
    }
    long long finishTime(int n, vector<vector<int>>& edges, vector<int>& baseTime) {
        adj.assign(n,{});
        t = baseTime;
        for(auto& e : edges) adj[e[0]].pb(e[1]);
        return helper(0);
    }
};