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
    bool isPossibleToRearrange(string s, string t, int k) {
        ll n = s.length(), i = 0, v = n/k;
        if(s == t) return true;
        um<string,ll> mp;
        while(i < n){
            string temp = s.substr(i,v);
            mp[temp]++,i += v;
        }
        i = 0;
        while(i < n){
            string temp = t.substr(i,v);
            if(!mp.count(temp)) return false;
            else (mp[temp] == 1) ? mp.erase(temp) : mp[temp]--;
            i += v;
        }
        return true;
    }
};