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
#define pob pop_back
class Solution {
public:
    bool checkString(string s) {
        ll n = s.length();
        ll li = -1, li2 = -1;
        f(i, 0, n) if (s[i] == 'a') li = i;
        f(i, 0, n) {
            if (s[i] == 'b') {
                li2 = i;
                break;
            }
        }
        if (li2 == -1 || li == -1)
            return true;
        else if (li > li2)
            return false;
        else
            return true;
    }
};