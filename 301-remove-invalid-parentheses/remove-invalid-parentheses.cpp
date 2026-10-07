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
private:
    void helperf(string s, vector<string>& ans, ll i, ll j) {
        ll x = 0;
        ll n = s.length();
        f(k, i, n) {
            if (s[k] == '(')
                x++;
            else if (s[k] == ')')
                x--;
            if (x >= 0)
                continue;
            f(l, j, k + 1) {
                if (s[l] == ')' && (l == j || s[l - 1] != ')'))
                    helperf(s.substr(0, l) + s.substr(l + 1), ans, k, l);
            }
            return;
        }
        helperb(s, ans, n - 1, n - 1);
    }
    void helperb(string s, vector<string>& ans, ll i, ll j) {
        ll x = 0;
        rf(k, i, 0) {
            if (s[k] == ')')
                x++;
            else if (s[k] == '(')
                x--;
            if (x >= 0)
                continue;
            rf(l, j, k) {
                if (s[l] == '(' && (l == j || s[l + 1] != '('))
                    helperb(s.substr(0, l) + s.substr(l + 1), ans, k - 1,
                            l - 1);
            }
            return;
        }
        ans.pb(s);
    }

public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        helperf(s, ans, 0, 0);
        return ans;
    }
};