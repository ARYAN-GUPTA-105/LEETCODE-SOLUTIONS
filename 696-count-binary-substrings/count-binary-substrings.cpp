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
    int countBinarySubstrings(string s) {
        ll n = s.length(), ans = 0, p = 0, st = 1;
        f(i,1,n){
            if(s[i] == s[i-1]) st++;
            else p = st, st = 1;
            if(st <= p) ans++;
        }
        return ans;
    }
};