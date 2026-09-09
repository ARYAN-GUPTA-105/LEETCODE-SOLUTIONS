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
    long long countCommas(long long n) {
        if(n <= 999) return 0;
        ll cnt = 0;
        ll st = 1000;
        while(st <= n){
            cnt += n - st + 1;
            st *= 1000;
        }
        return cnt;
    }
};