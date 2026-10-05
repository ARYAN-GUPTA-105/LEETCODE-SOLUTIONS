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
    int scoreOfParentheses(string s) {
        ll ans = 0, run = 0, n = s.length();
        f(i, 0, n) {
            if (s[i] == '(')
                run++;
            else {
                run--;
                if (s[i - 1] == '(')
                    ans += 1 << run;
            }
        }
        return ans;
    }
};