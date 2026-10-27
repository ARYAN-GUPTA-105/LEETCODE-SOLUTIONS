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
    int numSubmatrixSumTarget(vector<vector<int>>& mat, int target) {
        ll m = mat.size(), n = mat[0].size(), ans = 0;
        f(i,0,m) f(j,1,n) mat[i][j] += mat[i][j-1];
        um<ll,ll> mp;
        f(i,0,n){
            f(j,i,n){
                mp = {{0,1}};
                ll curr = 0;
                f(k,0,m){
                    curr += mat[k][j] - (i > 0 ? mat[k][i-1] : 0);
                    ans += mp.find(curr - target) != mp.end() ? mp[curr - target] : 0;
                    mp[curr]++;
                }
            }
        }
        return ans;
    }
};