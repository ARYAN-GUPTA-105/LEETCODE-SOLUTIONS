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
    int minMoves(vector<int>& nums) {
        ll n = nums.size();
        ll mn = *min_element(nums.begin(),nums.end());
        ll ans = 0;
        f(i,0,n) ans += (nums[i] - mn);
        return ans;
    }
};