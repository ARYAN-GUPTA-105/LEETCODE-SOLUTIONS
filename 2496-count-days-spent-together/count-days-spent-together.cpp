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
    ll helper(string& d) {
        int nums[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        ll m = stoi(d.substr(0,2));
        ll dy = stoi(d.substr(3,2));
        return nums[m - 1] + dy;
    }
    int countDaysTogether(string aa, string la, string ab, string lb) {
        ll start = max(helper(aa), helper(ab));
        ll end = min(helper(la), helper(lb));
        int ans = end - start + 1;
        return max(0,ans);
    }
};