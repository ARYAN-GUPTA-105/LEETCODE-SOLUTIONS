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
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        f(i,0,m){
            string curr;
            f(j,0,n) curr.pb('#');
            ans.pb(curr);
        }
        f(i,0,m) ans[i][0] = '.';
        f(i,1,n) ans[m-1][i] = '.';
        return ans; 
    }
};