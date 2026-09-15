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
    vi fans;
    ll diff = INT_MAX;
    void helper(ll n, ll k, vi ans){
        if(ans.size() == k - 1){
           ans.pb(n);
           sort(ans.begin(),ans.end());
           if(ans[ans.size() - 1] - ans[0] < diff) fans = ans, diff = ans[ans.size() - 1] - ans[0];
           return;
        }
        f(i,1,n+1){
            if(n % i == 0){
                ans.pb(i);
                helper(n/i,k,ans);
                ans.pop_back();
            }
        }
    }
    vector<int> minDifference(ll n, ll k) {
        vi ans;
        helper(n,k,ans);
        return fans;
    }
};