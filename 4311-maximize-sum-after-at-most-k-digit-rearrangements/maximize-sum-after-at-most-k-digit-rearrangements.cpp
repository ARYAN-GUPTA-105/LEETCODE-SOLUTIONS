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
    long long maximizeSum(vector<int>& nums, int k) {
        ll n = nums.size();
        vll vec;
        f(i,0,n){
            vll v;
            ll curr = nums[i];
            while(curr > 0){
                v.pb(curr % 10);
                curr /= 10;
            }
            sort(v.rbegin(),v.rend());
            ll num = 0;
            f(j,0,v.size()){
              num = num * 10 + v[j];
            }
            vec.pb(num - nums[i]);
        }
        sort(vec.rbegin(),vec.rend());
        ll ans = 0;
        f(i,0,n) ans += nums[i];
        f(i,0,k) ans += vec[i];
        return ans;
    }
};