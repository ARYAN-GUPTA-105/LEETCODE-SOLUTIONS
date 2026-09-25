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
    set<string> ans;
    void helper(string s) {
        ll r = s.find('}');
        if (r == string::npos) {
            ans.insert(s);
            return;
        }
        ll l = s.rfind('{', r);
        string lt = s.substr(0, l);
        string rt = s.substr(r + 1);
        string i = s.substr(l + 1, r - l - 1);
        string p;
        stringstream ss(i);
        while (getline(ss, p, ',')) {
            helper(lt + p + rt);
        }
    }
    vector<string> braceExpansionII(string e) {
        helper(e);
        return vector<string>(ans.begin(), ans.end());
    }
};