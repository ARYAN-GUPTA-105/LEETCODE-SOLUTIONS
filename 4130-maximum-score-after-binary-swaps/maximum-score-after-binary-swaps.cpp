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
    long long maximumScore(vector<int>& nums, string s) {
        ll n = nums.size();
        vll pos;
        f(i, 0, n) {
            if (s[i] - '0')
                pos.pb(i);
        }
        if (pos.empty())
            return 0;
        priority_queue<ll> pq;
        ll idx = 0, ans = 0;
        f(i, 0, n) {
            pq.push(nums[i]);
            if (i == pos[idx])
                ans += pq.top(), pq.pop(), idx++;
            if (idx == pos.size())
                break;
        }
        return ans;
    }
};