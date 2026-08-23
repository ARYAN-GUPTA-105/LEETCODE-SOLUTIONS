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
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vi ans(n, 0);
        int rev = 0;
        if (k == 0)
            return ans;
        if (k < 0) {
            k = -k;
            rev = 1;
            reverse(code.begin(), code.end());
        }
        f(i, 0, n) {
            int curr = 0;
            f(j, 0, k) curr += code[(i + j + 1) % n];
            ans[i] = curr;
        }
        if(rev) reverse(ans.begin(), ans.end());
        return ans;
    }
};