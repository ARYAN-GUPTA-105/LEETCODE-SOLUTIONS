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
    int countServers(vector<vector<int>>& grid) {
        um<ll,ll> str, stc;
        ll m = grid.size(), n = grid[0].size(), ans = 0;
        f(i,0,m) f(j,0,n) if(grid[i][j]) str[i]++, stc[j]++;
        f(i,0,m) f(j,0,n) if(grid[i][j] && (str.count(i) || stc.count(j)) && !(str[i] == 1 && stc[j] == 1)) ans++;
        return ans;
    }
};