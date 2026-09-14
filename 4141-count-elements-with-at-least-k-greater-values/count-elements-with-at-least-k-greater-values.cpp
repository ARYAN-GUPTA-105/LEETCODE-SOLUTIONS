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
    int countElements(vector<int>& nums, int k) {
        if(!k) return nums.size();
        ll n = nums.size();
        sort(nums.begin(), nums.end());
        ll ans = 0;
        f(i,0,n){
            if(nums[i] < nums[n-k]) ans++;
        }
        return ans;
    }
};