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
    int helper(int i, vi& p) {
        if (i == p[i])
            return i;
        return p[i] = helper(p[i], p);
    }
    void uni(int i, int j, vi& p) {
        int ri = helper(i, p), rj = helper(j, p);
        if (ri != rj)
            p[ri] = rj;
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.length();
        vi p(n);
        f(i, 0, n) p[i] = i;
        for (auto& x : pairs)
            uni(x[0], x[1], p);
        unordered_map<int, vi> gi;
        unordered_map<int, string> gc;
        f(i, 0, n) {
            int root = helper(i, p);
            gi[root].pb(i);
            gc[root].pb(s[i]);
        }
        string ans = s;
        for (auto& x : gi) {
            int root = x.first;
            string c = gc[root];
            vi indi = x.second;
            sort(c.begin(), c.end());
            f(k, 0, indi.size()) ans[indi[k]] = c[k];
        }
        return ans;
    }
};