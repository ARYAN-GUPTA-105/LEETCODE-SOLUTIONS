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
    long long lastInteger(long long n) {
        ll h = 1, s = 1, bc = n;
        bool l = true;
        while(bc > 1){
            if(!l && !(bc % 2)) h += s;
            bc = (bc + 1)/2;
            s *= 2;
            l = !l;
        }
        return h;
    }
};