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
    string reverseParentheses(string s) {
        vector<string> st;
        string ans = "";
        for (char ch : s) {
            if (ch == '(')
                st.pb(ans), ans = "";
            else if (ch == ')') {
                reverse(ans.begin(), ans.end());
                string p = st.back();
                st.pop_back();
                ans = p + ans;
            } else
                ans += ch;
        }
        return ans;
    }
};