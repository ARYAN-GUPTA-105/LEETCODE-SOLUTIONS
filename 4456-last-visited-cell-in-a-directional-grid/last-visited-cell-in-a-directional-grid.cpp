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
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        ll m = grid.size(), n = grid[0].size();
        int r = 0, c = 0;
        vvll vis(m,vll(n,0));
        vis[0][0] = 1;
        while(true){
              if(grid[r][c] == 'L'){
                c--;
                if(c < 0) return {r,c+1};
                if(vis[r][c]) return {r,c+1};
              }
              else if(grid[r][c] == 'R'){
                c++;
                if(c == n) return {r,c-1};
                if(vis[r][c]) return {r,c-1};
              }
              else if(grid[r][c] == 'U'){
                r--;
                if(r < 0) return {r+1,c};
                if(vis[r][c]) return {r+1,c};
              }
              else{
                r++;
                if(r == m) return {r-1,c};
                if(vis[r][c]) return {r-1,c};
              }
              vis[r][c] = 1;
            }
        return {r,c};
    }
};