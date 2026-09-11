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
    ll helper(ll n,ll p){
        if(!p) return (ll)1;
        ll ans = helper(n,p/2);
        ans = (ans * ans) % mod;
        if(p % 2) ans = (ans * n) % mod;
        return ans;
    }
    int sumOfNumbers(int l, int r, int k) {
        ll add = 0;
        f(i,l,r+1) add += i;
        ll freq = helper(r - l + 1,(ll)k - 1);
        ll ans = (add * freq) % mod;
        ll samooh = (helper(10,k) - 1 + mod) % mod;
        samooh = (samooh * helper(9,mod-2)) % mod;
        ans = (ans * samooh) % mod;
        return ans;
    }
};