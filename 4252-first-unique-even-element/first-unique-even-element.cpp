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
    int firstUniqueEven(vector<int>& nums) {
        vll freq(101,0);
        f(i,0,nums.size()) freq[nums[i]]++;
        f(i,0,nums.size()){
            if(nums[i] % 2 == 0 && freq[nums[i]] == 1) return nums[i];
        }
        return -1;
    }
};