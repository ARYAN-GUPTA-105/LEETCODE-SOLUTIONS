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
    string evaluate(string s, vector<vector<string>>& k) {
        um<string, string> mp;
        f(i, 0, k.size()) { mp[k[i][0]] = k[i][1]; }
        ll i = 0;
        string ans;
        while (i < s.length()) {
            if (s[i] == '(') {
                string curr;
                i++;
                while (s[i] != ')')
                    curr += s[i++];
                i++;
                if (mp.find(curr) != mp.end())
                    ans += mp[curr];
                else
                    ans += '?';
            } else
                ans += s[i++];
        }
        return ans;
    }
};