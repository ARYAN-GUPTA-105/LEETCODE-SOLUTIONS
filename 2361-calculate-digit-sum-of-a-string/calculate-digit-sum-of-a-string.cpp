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
    string digitSum(string s, int k) {
        while (s.length() > k) {
            ll curr = 0, t = 0;
            string str;
            f(i, 0, s.length()) {
                curr += s[i] - '0';
                t++;
                if (t == k) {
                    str += to_string(curr);
                    curr = 0;
                    t = 0;
                }
            }
            if(t != 0)
            str += to_string(curr);
            s = str;
        }
        return s;
    }
};