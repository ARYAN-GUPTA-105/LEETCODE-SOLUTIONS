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
    int minSwaps(vector<int>& nums) {
        vector<pair<ll, ll>> vec;
        ll n = nums.size();
        f(i, 0, n) {
            ll val = nums[i], sum = 0;
            while (val > 0) {
                sum += val % 10;
                val /= 10;
            }
            vec.pb({sum, i});
        }
        sort(vec.begin(), vec.end(), [&nums](auto a, auto b) {
            if (a.first == b.first) return nums[a.second] < nums[b.second];
            else return a.first < b.first;
        });
        ll ans = 0;
        us<ll> st;
        f(i, 0, n) {
            if (st.count(i)) continue;
            auto it = vec[i];
            ll cnt = 0;
            if (it.second == i) continue;
            ll j = i;
            while (!st.count(j)) st.insert(j), j = vec[j].second, cnt++;
            ans += (cnt - 1);
        }
        return ans;
    }
};