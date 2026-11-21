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
    um<ll,vll> mp;
    vi v, ans;
    void helper(string& s, vi& p, ll curr){
        ll c = s[curr] - 'a', l = v[c];
        v[c] = curr;
        for(auto it : mp[curr]) helper(s,p,it);
        v[c] = l;
        if(curr != 0){
            ll t = p[curr];
            if(l != -1) t = l;
            p[curr] = t;
            ans[t] += ans[curr];
        }
    }
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        ll n = parent.size();
        f(i,1,n) mp[parent[i]].pb(i);
        ans.assign(n,1), v.assign(26,-1), helper(s,parent,0);
        return ans;
    }
};