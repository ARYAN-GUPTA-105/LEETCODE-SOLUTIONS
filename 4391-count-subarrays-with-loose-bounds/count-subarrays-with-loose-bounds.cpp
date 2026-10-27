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
    long long countSubarrays(vector<int>& nums, int mnk, int mxk) {
        ll n = nums.size(), i = 0, j = 0, mn = nums[0], mx = nums[0], ans = 0;
        while(j < n){
            mn = min((ll)nums[j],mn), mx = max((ll)nums[j],mx);
            j++;
            if(mn < mnk || mx > mxk){
                i = j;
                if(j < n) mn = nums[j], mx = nums[j];
            }
            else ans += (j - i);
        }
        return ans;
    }
};