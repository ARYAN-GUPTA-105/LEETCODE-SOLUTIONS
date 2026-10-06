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
    int minAddToMakeValid(string s) {
        ll n = s.length(), ans = 0;
        ll fans = 0;
        f(i, 0, n) {
            if (s[i] == '(')
                ans++;
            else {
                if (ans > 0)
                    ans--;
                else
                    fans++;
            }
        }
        return ans + fans;
    }
};