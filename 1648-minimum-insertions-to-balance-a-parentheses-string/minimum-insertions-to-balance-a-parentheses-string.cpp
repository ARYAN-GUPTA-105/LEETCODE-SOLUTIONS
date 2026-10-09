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
    int minInsertions(string s) {
        ll n = s.length(), o = 0, c = 0;
        f(i, 0, n) {
            if (s[i] == '(') {
                c += 2;
                if (c % 2 == 1) {
                    o++;
                    c--;
                }
            } else {
                c--;
                if (c < 0) {
                    c += 2;
                    o++;
                }
            }
        }
        return o + c;
    }
};