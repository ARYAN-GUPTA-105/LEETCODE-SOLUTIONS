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
    ll ans = 0;
    void helper(string& s, us<string>& st, ll idx) {
        if (idx == s.length()) {
            ans = max(ans, (ll)st.size());
            return;
        }
        for (ll i = 1; idx + i <= s.length(); i++) {
            string curr = s.substr(idx, i);
            if (st.find(curr) == st.end()) {
                st.insert(curr);
                helper(s, st, idx + i);
                st.erase(curr);
            }
        }
    }
    int maxUniqueSplit(string s) {
        us<string> st;
        helper(s, st, 0);
        return ans;
    }
};