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
    ll dp[1005][1005][2];
    ll helper(ll n, ll k, ll idx, ll st){
        if(!k) return 1;
        if(idx == n) return 0;
        if(dp[idx][k][st] != -1) return dp[idx][k][st];
        ll ans = 0;
        if(st){
            ans = (ans + helper(n,k-1,idx,false)) % mod;
            ans = (ans + helper(n,k,idx+1,true)) % mod;
        }
        else{
            ans = (ans + helper(n,k,idx+1,true)) % mod;
            ans = (ans + helper(n,k,idx+1,false)) % mod;
        }
        return dp[idx][k][st] = ans;
    }
    int numberOfSets(ll n, ll k) {
        memset(dp,-1,sizeof(dp));
        return helper(n,k,0,false);
    }
};