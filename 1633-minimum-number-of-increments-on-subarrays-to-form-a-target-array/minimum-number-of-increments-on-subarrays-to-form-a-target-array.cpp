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
    int minNumberOperations(vector<int>& t) {
        ll ans = t[0];
        ll n = t.size();
        f(i,1,n){
            if(t[i] > t[i-1]) ans += t[i] - t[i-1];
        }
        return ans;
    }
};