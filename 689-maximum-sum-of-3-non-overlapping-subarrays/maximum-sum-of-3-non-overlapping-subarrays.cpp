#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size(), mx = 0;
        vi sum(n+1,0), pl(n,0), pr(n,n-k), ans(3,0);
        f(i,0,n) sum[i+1] = sum[i] + nums[i];
        ll tot = sum[k] - sum[0];
        f(i,k,n){
            if(sum[i+1] - sum[i+1-k] > tot) pl[i] = i+1-k, tot = sum[i+1] - sum[i+1-k];
            else pl[i] = pl[i-1];
        }
        tot = sum[n] - sum[n-k];
        rf(i,n-k-1,0){
            if(sum[i+k] - sum[i] >= tot) pr[i] = i, tot = sum[i+k] - sum[i];
            else pr[i] = pr[i+1];
        }
        f(i,k,n-2*k+1){
            ll l = pl[i-1], r = pr[i+k];
            tot = (sum[i+k]-sum[i]) + (sum[l+k]-sum[l]) + (sum[r+k]-sum[r]);
            if(tot > mx) mx = tot, ans = {(int)l,i,(int)r};
        }
        return ans;
    }
};