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
    int peakValleyDifference(vector<int>& nums) {
        ll n = nums.size(), sp = 0, sv = 0;
        f(i,1,n-1){
            if(nums[i] > nums[i+1] && nums[i] > nums[i-1]) sp += nums[i];
            if(nums[i] < nums[i+1] && nums[i] < nums[i-1]) sv += nums[i];
        }
        return sp - sv;
    }
};