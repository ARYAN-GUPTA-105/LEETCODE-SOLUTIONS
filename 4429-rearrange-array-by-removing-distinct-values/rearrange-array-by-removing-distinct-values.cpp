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
    vector<int> rearrangeArray(vector<int>& nums) {
        map<ll, ll> mp;
        vi ans;
        for (ll x : nums)
            mp[x]++;
        while (mp.size() > 0) {
            vi curr;
            for (auto& it : mp) {
                ans.pb(it.first);
                it.second--;
                if (it.second == 0)
                    curr.pb(it.first);
            }
            for(int x : curr) mp.erase(x);
        }
        return ans;
    }
};