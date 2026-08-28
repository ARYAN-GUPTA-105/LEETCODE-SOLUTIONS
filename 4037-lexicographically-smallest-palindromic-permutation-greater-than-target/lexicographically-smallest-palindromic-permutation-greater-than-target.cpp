#include <bits/stdc++.h>
using namespace std;

#define ll long long
// #define endl '\n'

using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        vll cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;
        string mid = "";
        vll pairs(26, 0);
        f(i, 0, 26) {
            if (cnt[i] % 2 != 0) {
                if (!mid.empty())
                    return "";
                mid += (char)('a' + i);
            }
            pairs[i] = cnt[i] / 2;
        }
        ll len = s.length() / 2;
        f(i, 0, len) pairs[target[i] - 'a']--;
        bool can = true;
        for (ll p : pairs)
            if (p < 0)
                can = false;
        if (can) {
            string st = target.substr(0, len);
            string end = st;
            reverse(end.begin(), end.end());
            string ans = st + mid + end;
            if (ans > target)
                return ans;
        }
        rf(i, len - 1, 0) {
            pairs[target[i] - 'a']++;
            can = true;
            for (ll p : pairs)
                if (p < 0)
                    can = false;
            if (!can)
                continue;
            f(j, target[i] - 'a' + 1, 26) {
                if (pairs[j] > 0) {
                    pairs[j]--;
                    string st = target.substr(0, i);
                    st += (char)('a' + j);
                    f(k, 0, 26) st.append(pairs[k], (char)('a' + k));
                    string end = st;
                    reverse(end.begin(), end.end());
                    string ans = st + mid + end;
                    return ans;
                }
            }
        }
        return "";
    }
};