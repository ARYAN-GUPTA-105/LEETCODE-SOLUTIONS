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
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        ll mod = 1e9 + 7;
        unordered_map<int,int> mp;
        for(ll x : nums){
           ll rev = 0;
           ll val = x;
           while(x > 0){
            rev = rev * 10 + x % 10;
            x /= 10;
           }
           val -= rev;
           mp[val]++;
        }
        ll ans = 0;
        for(auto &x : mp){
            ll s = x.second % mod;
            ans += ((s % mod) * ((s - 1) % mod)/2) % mod;
        }
        return ans % mod;
    }
};