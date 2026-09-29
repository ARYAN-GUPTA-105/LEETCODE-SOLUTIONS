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
    ll helper(ll node, vector<bool>& vis,vector<vector<pair<ll, ll>>>& adj) {
        vis[node] = true;
        ll c = 0;
        for (auto& it : adj[node]) {
            ll n = it.first;
            ll p = it.second;
            if (!vis[n]) {
                c += p;
                c += helper(n, vis, adj);
            }
        }
        return c;
    }
    int minReorder(int n, vector<vector<int>>& c) {
        vector<vector<pair<ll, ll>>> adj(n);
        for (auto& e : c) {
            ll u = e[0], v = e[1];
            adj[u].pb({v, 1});
            adj[v].pb({u, 0});
        }
        vector<bool> vis(n, false);
        return helper(0, vis, adj);
    }
};