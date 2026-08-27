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
    string lexGreaterPermutation(string s, string target) {
        vi cnt(26);
        for (char c : s)
            cnt[c - 'a']++;
        for (char c : target)
            cnt[c - 'a']--;
        rf(i, target.size() - 1, 0) {
            int c = target[i] - 'a';
            cnt[c]++;
            bool can = true;
            f(j, 0, 26) {
                if (cnt[j] < 0) {
                    can = false;
                    break;
                }
            }
            if (!can)
                continue;
            int agla = -1;
            f(j, c + 1, 26) {
                if (cnt[j] > 0) {
                    agla = j;
                    break;
                }
            }
            if (agla == -1)
                continue;
            cnt[agla]--;
            string ans = target.substr(0, i);
            ans += char('a' + agla);
            f(j, 0, 26) ans.append(cnt[j], char('a' + j));
            return ans;
        }
        return "";
    }
};