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
    string mergeCharacters(string s, int k) {
        string s2 = s;
        f(l, 0, 100) {
            bool can = false;
            f(i, 0, s2.size()) {
                f(j, i + 1, s2.size()) {
                    if (s2[i] == s2[j] && (j - i) <= k) {
                        s2.erase(j, 1);
                        can = true;
                        break;
                    }
                }
                if (can)
                    break;
            }
            if (!can)
                break;
        }
        return s2;
    }
};