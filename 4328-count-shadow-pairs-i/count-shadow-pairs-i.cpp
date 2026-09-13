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
    long long shadowPairs(vector<int>& nums) {
        ll ans = 0;
        stack<ll> st;
        ll n = nums.size();
        um<ll,ll> mp;
        f(i,0,n){
            while(!st.empty() && nums[i] < st.top()) mp[st.top()]--, st.pop();
            ans += (st.size() - mp[nums[i]]);
            st.push(nums[i]);
            mp[nums[i]]++;
        }        
        return ans;
    }
};