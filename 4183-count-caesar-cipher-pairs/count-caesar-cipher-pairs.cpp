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
class Solution {
public:
    long long countPairs(vector<string>& words) {
        unordered_map<string,int> mp;
        ll cnt = 0;
        for(string& w : words){
            int n = w.length();
            string curr(n,'a');
            int shift = w[0] - 'a';
            f(i,0,n) curr[i] = 'a' + (w[i] - 'a' - shift + 26) % 26;
            cnt += mp[curr];
            mp[curr]++;
        }
        return cnt;
    }
};