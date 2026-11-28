//tantra mantra 
#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<int>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvii = vector<vi>;
#define f(i, a, n) for (ll i = a; i < n; i++)
#define rf(i, a, n) for (ll i = a; i >= n; i--)
#define pb push_back
#define um unordered_map
#define us unordered_set
class Solution {
public:
    int maximumSaleItems(vvii& items, int budget) {
        ll n = items.size(), mn = INT_MAX;
        vll cnt(n+1), mult(n+1);
        for(auto &it : items) cnt[it[0]]++;
        f(i,1,n+1)
            for(ll j = i; j <= n; j += i)
                mult[i] += cnt[j];
        vector<pair<ll,ll>> v;
        for(auto &it : items){
            mn = min(mn,(ll)it[1]);
            ll g = mult[it[0]]-1;
            if(g > 0) v.pb({it[1],g});
        }
        sort(v.begin(),v.end());
        ll ans = 0, b = budget;
        for(auto &[p,g] : v){
            if(p > 2*mn) break;
            ll c = min(g,b/p);
            ans += 2*c;
            b -= c*p;
        }
        return ans + b/mn;
    }
};