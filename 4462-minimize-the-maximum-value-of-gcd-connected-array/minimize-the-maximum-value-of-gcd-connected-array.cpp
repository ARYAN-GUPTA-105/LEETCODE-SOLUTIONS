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
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;
        ll p = value;
        for (ll i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }
        if (value - p + 2 <= 2ll * index) return -1;
        if (index == n - 1) return value;
        return value + p - 2 + 2ll * (n - 1 - index);
    }
};