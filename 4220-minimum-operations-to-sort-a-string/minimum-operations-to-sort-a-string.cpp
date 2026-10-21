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
    int minOperations(string s) {
        ll n = s.size(); bool pos = 1;
        f(i,1,n){
            if(s[i] < s[i-1]){
                pos = 0;break;
            }
        }
        if(pos) return 0;
        if(n == 2) return -1;
        char mn = *min_element(s.begin(),s.end());
        char mx = *max_element(s.begin(),s.end());
        if(s[0] == mn || s[n-1] == mx) return 1;
        f(i,1,n-1) if(s[i] == mn || s[i] == mx) return 2;
        return 3;
    }
};