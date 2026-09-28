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
    int distinctPoints(string s, int k) {
        set<pair<ll, ll>> st;
        st.insert({0, 0});
        ll x = 0, y = 0;
        f(i, k, s.size()) {
            if (s[i] == 'U')
                y++;
            if (s[i] == 'D')
                y--;
            if (s[i] == 'L')
                x++;
            if (s[i] == 'R')
                x--;
            if (s[i - k] == 'U')
                y--;
            if (s[i - k] == 'D')
                y++;
            if (s[i - k] == 'L')
                x--;
            if (s[i - k] == 'R')
                x++;
            st.insert({x, y});
        }
        return st.size();
    }
};