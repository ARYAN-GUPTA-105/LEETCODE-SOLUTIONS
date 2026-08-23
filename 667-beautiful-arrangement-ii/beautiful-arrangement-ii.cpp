#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vi ans;
        int i = 1, j = n;
        while (i <= j) {
            if (k > 1) {
                if (k % 2)
                    ans.pb(i), i++;
                else
                    ans.pb(j), j--;
                k--;
            } else
                ans.pb(i), i++;
        }
        return ans;
    }
};