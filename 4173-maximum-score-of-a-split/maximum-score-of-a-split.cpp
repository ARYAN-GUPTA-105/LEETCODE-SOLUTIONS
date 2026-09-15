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
    long long maximumScore(vector<int>& nums) {
        ll n = nums.size();
        vll smn(n);
        smn[n-1] = nums[n-1];
        rf(i,n-2,0){
          smn[i] = min(smn[i+1],(ll)nums[i+1]);
        }
        ll sum = 0;
        ll ans = INT_MIN;
        f(i,0,n-1){
          sum += nums[i];
          ans = max(sum - smn[i],ans);
        }
        return ans;
    }
};