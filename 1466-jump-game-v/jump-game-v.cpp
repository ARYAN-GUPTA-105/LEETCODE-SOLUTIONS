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
    ll n;
    vll nums;
    ll helper(vi& arr, ll d, ll i) {
        if (nums[i] != -1)
            return nums[i];
        ll ans = 1;
        ll mn = max(1LL * 0, i - d);
        rf(j, i - 1, mn) {
            if (arr[j] >= arr[i])
                break;
            ans = max(ans, 1 + helper(arr, d, j));
        }
        mn = min(n - 1, i + d);
        f(j, i + 1, mn + 1) {
            if (arr[j] >= arr[i])
                break;
            ans = max(ans, 1 + helper(arr, d, j));
        }
        return nums[i] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();
        nums.resize(n, -1);
        ll ans = 1;
        f(i, 0, n) ans = max(ans, helper(arr, d, i));
        return ans;
    }
};