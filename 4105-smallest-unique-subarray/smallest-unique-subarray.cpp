//tantra mantra
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
    int smallestUniqueSubarray(vector<int>& nums) {
        ll n = nums.size(), m1 = 1000000007, m2 = 1000000009, b1 = 1000003, b2 = 1000033;
        vll h1(n+1), h2(n+1), p1(n+1), p2(n+1);
        p1[0] = p2[0] = 1;
        f(i,0,n){
            h1[i+1] = (h1[i] * b1 + nums[i]) % m1;
            h2[i+1] = (h2[i] * b2 + nums[i]) % m2;
            p1[i+1] = p1[i] * b1 % m1;
            p2[i+1] = p2[i] * b2 % m2;
        }
        auto helper = [&](int len) ->bool{
            map<pair<ll,ll>, ll> cnt;
            f(i,0,n - len + 1){
                ll a = (h1[i+len] - h1[i] * p1[len] % m1 + m1) % m1;
                ll b = (h2[i+len] - h2[i] * p2[len] % m2 + m2) % m2;
                cnt[{a,b}]++;
            }
            for(auto& e : cnt) if(e.second == 1) return true;
            return false;
        };
        ll lo = 1, hi = n, ans = n;
        while(lo <= hi){
            ll mid = lo + (hi - lo) / 2;
            if(helper(mid)) ans = mid, hi = mid - 1;
            else lo = mid + 1;
        }
        return ans;
    }
};