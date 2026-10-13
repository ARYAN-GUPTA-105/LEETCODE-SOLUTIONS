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
    long long maxAlternatingSum(vector<int>& nums) {
        ll n = nums.size();
        vll arr;
        f(i, 0, n) arr.pb(abs(nums[i]));
        sort(arr.begin(), arr.end());
        ll i = 0, j = n - 1;
        vll ans;
        while (i <= j) {
            ans.pb(arr[j]);
            ans.pb(arr[i]);
            j--, i++;
        }
        ll sum = 0;
        i = 0;
        while (i < n) {
            if (i < n)
                sum += ans[i] * ans[i];
            i++;
            if (i < n)
                sum -= ans[i] * ans[i];
            i++;
        }
        return sum;
    }
};