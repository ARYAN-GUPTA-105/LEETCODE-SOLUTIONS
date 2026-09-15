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
    long long minimumCost(string s, string t, ll fc, ll sc, ll cc) {
        ll f1 = 0, f0 = 0;
        f(i, 0, s.length()) {
            if (s[i] == '0' && t[i] == '1')
                f1++;
            else if (s[i] == '1' && t[i] == '0')
                f0++;
        }
        ll cd = min(sc, 2LL * fc), cs = min(cc + sc, 2LL * fc);
        ll dp = min(f1, f0);
        ll bc = abs(f1 - f0), sp = bc / 2, akela = bc % 2;
        ll tc = (dp * cd) + (sp * cs) + (akela * fc);
        return tc;
    }
};