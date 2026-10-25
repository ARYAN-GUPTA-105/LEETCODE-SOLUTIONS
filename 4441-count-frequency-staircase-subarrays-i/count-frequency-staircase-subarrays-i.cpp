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
    int countStaircase(vector<int>& nums) {
        ll n = nums.size(), ans = 0;
        f(i, 0, n) {
            vll freq;
            um<ll, ll> mp;
            f(j, i, n) {
                ll curr = nums[j];
                if (mp.find(curr) == mp.end()) mp[curr] = freq.size(), freq.pb(1);
                else freq[mp[curr]]++;
                bool pos = true;
                f(k, 0, freq.size()) if (freq[k] != k + 1) {
                    pos = false;
                    break;
                }
                if (pos) ans++;
            }
        }
        return ans;
    }
};