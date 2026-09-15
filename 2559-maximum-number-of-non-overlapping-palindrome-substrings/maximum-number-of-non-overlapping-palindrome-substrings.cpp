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
    int maxPalindromes(string s, int k) {
        ll n = s.size(), ans = 0, last = -1;
        f(i,0,n){
            for(ll l : {i-1,i}){
                ll r = i;
                while(l >= 0 && r < n && s[l] == s[r]){
                    if(r - l + 1 >= k && l > last){
                        ans++;
                        last = r;
                        break;
                    }
                    l--, r++;
                }
            }
        }
        return ans;
    }
};