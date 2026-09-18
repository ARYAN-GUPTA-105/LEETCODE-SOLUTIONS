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
    void helper(string& s, char x, char y, ll& mx){
        ll n = s.length();
        ll sum = 0;
        um<ll,ll> mp;
        mp[0] = -1;
        f(i,0,n){
            if(s[i] == x) sum++;
            else if(s[i] == y) sum--;
            else{
                mp.clear(), mp[0] = i, sum = 0;
                continue;
            }
            if(mp.find(sum) != mp.end()) mx = max(mx,i - mp[sum]);
            else mp[sum] = i;
        }

    }
    int longestBalanced(string s) {
        ll n = s.length(), mx = 1, len = 1;
        f(i,1,n){
            if(s[i] == s[i-1]) len++;
            else mx = max(mx,len), len = 1;
        }
        mx = max(mx,len);
        helper(s,'a','b',mx);
        helper(s,'b','c',mx);
        helper(s,'a','c',mx);
        map<pair<ll,ll>,ll> mp;
        mp[{0,0}] = -1;
        vll cnt(3,0);
        f(i,0,n){
            cnt[s[i] - 'a']++;
            ll cntab = cnt[0] - cnt[1];
            ll cntac = cnt[0] - cnt[2];
            if(mp.find({cntab,cntac}) != mp.end()) mx = max(mx,i - mp[{cntab,cntac}]);
            else mp[{cntab,cntac}] = i;
        }
        return mx;
    }
};