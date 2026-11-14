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
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        ll n = nums.size(), ans = INT_MAX;
        f(i,0,n - l + 1){
            ll curr = 0;
            f(j,i,i+l){
              curr += nums[j];
            }
            if(curr > 0)
            ans = min(ans,curr);
            f(j,i+l,min(i+r,(int)n)){
                curr += nums[j];
                if(curr > 0)
                ans = min(ans,curr);
            }
            if(curr > 0)
            ans = min(ans,curr);
        }
        return (ans != INT_MAX) ? ans : -1;
    }
};