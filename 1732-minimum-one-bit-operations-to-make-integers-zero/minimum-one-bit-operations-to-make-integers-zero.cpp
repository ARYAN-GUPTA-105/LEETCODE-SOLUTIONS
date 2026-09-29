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
    int minimumOneBitOperations(int n) {
        ll ans;
        for (ans = 0; n > 0; n &= n - 1)
            ans = -(ans + (n ^ (n - 1)));
        return abs(ans);
    }
};