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
    int countSuffix(vector<int>& nums, vector<int>& target) {
        ll n = nums.size();
        um<int, int> mp, mp2;
        f(i, 0, n) mp[nums[i]]++, mp2[target[i]]++;
        if (mp != mp2) return 0;
        ll idx = n - 1, idx2 = 0;
        while (idx >= 1 && target[idx] <= target[idx - 1]) idx--;
        idx = max(1ll*0,idx);
        while(idx2 < n && target[idx2] == nums[idx2]) idx2++;
        idx2 = min(idx2,n-1);
        if(idx2 < idx) return 0;
        ll ans = abs(idx2 - idx) + 1;
        return ans;
    }
};