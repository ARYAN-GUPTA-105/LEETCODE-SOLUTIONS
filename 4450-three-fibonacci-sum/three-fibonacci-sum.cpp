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
    bool threeFibonacciSum(int n) {
        ll i = 0, j = 1, k = 1;
        while(i + j + k <= n){
            ll nxt = j + k;
            if(i + j + k == n) return true;
            i = j, j = k, k = nxt;
        }
        return false;
    }
};