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
class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vi a = nums;
        sort(a.begin(),a.end());
        vvii grp;
        unordered_map<int,int> mp;
        int idx = -1;
        f(i,0,a.size()){
            if(i == 0 || a[i] - a[i-1] > limit){
                grp.pb({});
                idx++;
            }
            grp[idx].pb(a[i]);
            mp[a[i]] = idx;
        }
        vi b(grp.size(),0);
        f(i,0,nums.size()){
            int curr = mp[nums[i]];
            nums[i] = grp[curr][b[curr]];
            b[curr]++;
        }
        return nums;
    }
};