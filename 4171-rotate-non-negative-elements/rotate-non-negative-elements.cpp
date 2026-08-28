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
    vector<int> rotateElements(vector<int>& nums, int k) {
        vi pos, val;
        f(i,0,nums.size()) if(nums[i] >= 0) pos.pb(i), val.pb(nums[i]);
        if(pos.size() == 0) return nums;
        k %= pos.size();
        vi ans;
        ans.reserve(val.size());
        f(i,k,val.size()) ans.pb(val[i]);
        f(i,0,k) ans.pb(val[i]);
        f(t,0,pos.size()) nums[pos[t]] = ans[t];
        return nums;
    }
};