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
    int firstStableIndex(vector<int>& nums, int k) {
        ll n = nums.size();
        vll mx(n);
        vll mn(n);
        mx[0] = nums[0];
        f(i,1,n){
            mx[i] = max(mx[i-1],(ll)nums[i]);
        }
        mn[n-1] = nums[n-1];
        rf(i,n-2,0){
            mn[i] = min(mn[i+1],(ll)nums[i]);
        }
        f(i,0,n){
            ll score = mx[i] - mn[i];
            if(score <= k) return i;
        }
        return -1;
    }
};