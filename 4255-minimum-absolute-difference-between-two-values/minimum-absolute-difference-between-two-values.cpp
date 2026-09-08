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
    int minAbsoluteDifference(vector<int>& nums) {
        ll n = nums.size();
        ll ans = INT_MAX;
        f(i,0,n){
            if(nums[i] == 1){
                f(j,i+1,n) if(nums[j] == 2) ans = min(ans,(ll)abs(i - j));
            }
            else if(nums[i] == 2){
                f(j,i+1,n) if(nums[j] == 1) ans = min(ans,(ll)abs(i - j));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};