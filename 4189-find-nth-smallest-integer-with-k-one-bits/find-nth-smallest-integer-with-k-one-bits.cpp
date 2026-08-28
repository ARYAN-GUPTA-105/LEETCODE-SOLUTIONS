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
    long long nthSmallest(long long n, int k) {
        vvll bits(51,vll(51,0));
        f(i,0,51){
            bits[i][0] = 1;
            f(j,1,i+1) bits[i][j] = bits[i-1][j-1] + bits[i-1][j];
        }
        ll ans = 0, c = 0;
        rf(i,49,0){
            c = (k <= i ? bits[i][k] : 0);
            if(n > c) ans |= (1LL << i), n -= c,k--;
        }
        return ans;
    }
};