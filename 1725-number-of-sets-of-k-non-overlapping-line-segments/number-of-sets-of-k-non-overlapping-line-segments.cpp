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
    ll mod = 1e9 + 7;
    ll helper(ll b, ll e){
        ll ans = 1;
        while(e > 0){
            if(e & 1LL) ans = ans * b % mod;
            b = b * b % mod;
            e >>= 1LL;
        }
        return ans;
    }
    int numberOfSets(ll n, ll k) {
        ll x = n + k - 1;
        ll r = 2 * k;
        r = min(r,x-r);
        ll num = 1, denum = 1;
        f(i,1,r+1){
            num = num * (x - r + i) % mod;
            denum = denum * i % mod;
        }
        ll ide = helper(denum,mod-2);
        return (num * ide % mod);
    }
};