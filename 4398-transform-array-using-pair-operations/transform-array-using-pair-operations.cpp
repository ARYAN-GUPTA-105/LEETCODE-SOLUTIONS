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
    bool canTransform(vector<int>& s, vector<int>& t) {
        ll s1 = 0;
        ll s2 = 0;
        f(i,0,s.size()) s1 += s[i];
        f(i,0,t.size()) s2 += t[i];
        return s1 == s2;
    }
};