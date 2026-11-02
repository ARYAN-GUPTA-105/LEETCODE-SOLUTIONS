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
    int minMergedInteger(vector<int>& nums) {
        int n = nums.size(), ans = INT_MAX;
        f(i,0,n) {
            string s = to_string(nums[i++]) + to_string(nums[i]);
            int curr = stoi(s);
            ans = min(ans,curr);
        }
        return ans;
    }
};