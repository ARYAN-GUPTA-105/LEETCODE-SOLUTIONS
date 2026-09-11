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
    vector<int> minDistinctFreqPair(vector<int>& nums) {
        ll n = nums.size();
        vll freq(101,0);
        f(i,0,n) freq[nums[i]]++;
        f(i,1,101){
            if(freq[i] == 0) continue;
            f(j,i+1,101){
                if(freq[j] != freq[i] && freq[j] != 0) return {i,j};
            }
        }
        return {-1,-1};
    }
};