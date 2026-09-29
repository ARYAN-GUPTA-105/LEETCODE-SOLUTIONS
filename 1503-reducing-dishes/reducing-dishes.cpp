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
    int maxSatisfaction(vector<int>& s) {
        ll n = s.size(), x = 0, ans = 0;
        sort(s.rbegin(), s.rend());
        f(i, 0, n) {
            x += s[i];
            if (x < 0)
                break;
            ans += x;
        }
        return ans;
    }
};