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
    ll m, n;
    bool helper(vvii& grid,ll i,ll j){
        if(i < 0 || i >= m || j < 0 || j >= n) return false;
        if(grid[i][j]) return true;
        grid[i][j] = 1;
        return helper(grid,i+1,j) & helper(grid,i-1,j) & helper(grid,i,j-1) & helper(grid,i,j+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid[0].size(), m = grid.size();
        ll ans = 0;
        f(i,0,m) f(j,0,n) if(!grid[i][j]) ans += helper(grid,i,j);
        return ans;
    }
};