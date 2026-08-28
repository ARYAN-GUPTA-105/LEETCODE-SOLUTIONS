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
    int minimumPrefixLength(vector<int>& nums) {
        int idx = 0;
        f(i,1,nums.size()) if(nums[i] <= nums[i-1]) idx = i;
        return idx;
    }
};