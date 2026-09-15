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
    int minOperations(vector<int>& nums) {
        um<ll,ll> mp;
        us<ll> st;
        ll n = nums.size();
        f(i,0,n){
            if(mp.find(nums[i]) != mp.end()) mp[nums[i]]++, st.insert(nums[i]);
            else mp[nums[i]]++;
        }
        ll ans = 0, i = 0;
        while(st.size() > 0){
            ans++;
            f(j,1,4){
                if(i == n) break;
                mp[nums[i]]--;
                if(mp[nums[i]] < 2) st.erase(nums[i]);
                i++;
            }
        }
        return ans;
    }
};