#include <bits/stdc++.h>
using namespace std;
#define ll long long
using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (ll i = a; i < n; i++)
#define rf(i, a, n) for (ll i = a; i >= n; i--)
#define pb push_back
#define um unordered_map
#define us unordered_set

class Solution {
public:
    int helper(string& s, ll i, vll& l, vll& r) {
        ll rt = r[s[i] - 'a'];
        for (int j = i; j <= rt; j++) {
            if (l[s[j] - 'a'] < i)
                return -1;
            rt = max(rt, r[s[j] - 'a']);
        }
        return rt;
    }

    vector<string> maxNumOfSubstrings(string s) {
        vll l(26, INT_MAX);
        vll r(26, INT_MIN);
        vector<string> ans;
        f(i, 0, s.size()) {
            l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
            r[s[i] - 'a'] = i;
        }
        ll rt = -1;
        f(i, 0, s.size()) {
            if (i == l[s[i] - 'a']) {
                ll nr = helper(s, i, l, r);
                if (nr != -1) {
                    if (i > rt)
                        ans.push_back("");
                    rt = nr;
                    ans.back() = s.substr(i, rt - i + 1);
                }
            }
        }
        return ans;
    }
};