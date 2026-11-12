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
    int longestMonotonicSubarray(vector<int>& nums) {
        ll n = nums.size(), i = 1, ans = 0;
        bool w = (nums[1] > nums[0]) ? true : false;
        while(i < n){ 
            if(nums[i] == nums[i-1]){i++;continue;}
            ll curr = 0;
            if(w){
                while(i < n && nums[i] > nums[i-1]) curr++, i++;
                ans = max(ans,curr);
                w = !w;
            }
            else{
                while(i < n && nums[i] < nums[i-1]) curr++, i++;
                ans = max(ans,curr);
                w = !w;
            }
        }
        return ans+1;
    }
};