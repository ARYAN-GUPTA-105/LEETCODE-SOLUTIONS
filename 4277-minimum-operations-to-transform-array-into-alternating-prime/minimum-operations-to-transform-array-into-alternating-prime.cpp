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
    bool helper(ll x) {
        if (x == 1)
            return false;
        for (ll i = 2; i * i <= x; i++) {
            if (x % i == 0)
                return false;
        }
        return true;
    }
    int minOperations(vector<int>& nums) {
        ll n = nums.size();
        ll ans = 0;
        f(i,0,n){
            if(i % 2){
                if(helper(nums[i])){
                  while(helper(nums[i])) nums[i]++,ans++; 
                }
            }
            else{
                if(!helper(nums[i])){
                    while(!helper(nums[i])) nums[i]++,ans++;
                }
            }
        }
        return ans;
    }
};