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
    int minOperations(vector<int>& nums, vector<int>& l, int k) {
        ll n = nums.size(), c1 = 0, ans = 0;
        f(i,0,n){
            f(j,0,n-1-i){
                if(nums[j] > nums[j+1]){
                    if(l[j]) l[j] = 0, ans++;
                    if(l[j+1]) l[j+1] = 0, ans++;
                    swap(nums[j],nums[j+1]);
                    c1++;
                }
            }
        }
        if(ans > k) return -1;
        return ans + c1;   
    }
};