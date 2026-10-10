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
    long long minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1,
                               int k2) {
        ll n = n1.size();
        vll diff(1e5 + 5);
        f(i, 0, n) diff[abs(n1[i] - n2[i])]++;
        ll k = k1 + k2;
        rf(i, diff.size()-1, 0) {
            if (diff[i] <= k) {
                if (i < 2)
                    return 0;
                diff[i - 1] += diff[i];
                k -= diff[i];
                diff[i] = 0;
            } else {
                if (i == 0)
                    return 0;
                diff[i] -= k;
                diff[i - 1] += k;
                break;
            }
        }
        ll ans = 0;
        f(i, 1, diff.size()) ans += (diff[i] * i * i);
        return ans;
    }
};