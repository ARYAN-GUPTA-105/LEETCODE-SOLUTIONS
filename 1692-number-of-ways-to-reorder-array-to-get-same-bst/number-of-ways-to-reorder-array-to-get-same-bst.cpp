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
    ll mod = 1e9 +7;
    vvll vec;
    ll helper(vi& v) {
       ll n = v.size(); if(n < 3) return 1;
       vi lt, rt;
       f(i,1,n){
        if(v[i] < v[0]) lt.pb(v[i]);
        else rt.pb(v[i]);
       }
       return vec[n-1][lt.size()] * helper(lt) % mod * helper(rt) % mod;
    }
    int numOfWays(vector<int>& nums) {
        ll n = nums.size(); vec.assign(n+1,vll(n+1,0));
        f(i,0,n+1){
            vec[i][0] = 1;
            f(j,1,i+1) vec[i][j] = (vec[i-1][j-1] + vec[i-1][j]) % mod;
        }
        ll ans = (helper(nums) - 1 + mod) % mod;
        return ans;
    }
};