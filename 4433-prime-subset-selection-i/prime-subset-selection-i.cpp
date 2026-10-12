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
    vector<int> maxPrimes(int n, int s) {
        vi ans;
        if (n < 2 || s < 2)
            return ans;
        vector<bool> arr(n + 1, true);
        arr[0] = arr[1] = false;
        for (ll i = 2; 1LL * i * i <= n; i++) {
            if (arr[i]) {
                for (int j = i * i; j <= n; j += i)
                    arr[j] = false;
            }
        }
        ll sum = 0;
        f(i, 0, n + 1) {
            if (arr[i]) {
                if (sum + i <= s) {
                    ans.pb(i);
                    sum = sum + i;
                } else
                    return ans;
            }
        }
        return ans;
    }
};