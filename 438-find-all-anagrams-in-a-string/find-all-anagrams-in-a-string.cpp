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
    vector<int> findAnagrams(string s, string p) {
        ll n = s.length();
        um<char,ll> mp;
        vi ans;
        f(i,0,p.length()) mp[p[i]]++;
        um<char,ll> mp2;
        ll j = 0;
        f(i,0,s.length()){
            if(i < p.length()){
                mp2[s[i]]++;
            }
            else{
                if(mp2 == mp) ans.pb(j);
                mp2[s[j]]--;
                if(mp2[s[j]] == 0) mp2.erase(s[j]);
                j++;
                mp2[s[i]]++;
            }
        }
        if(mp2 == mp) ans.pb(j);
        return ans;
    }
};