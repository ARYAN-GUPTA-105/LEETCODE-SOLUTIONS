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
    int longestSubstring(string s, int k) {
        ll n = s.length();
        um<char, int> freq;
        f(i, 0, n) freq[s[i]]++;
        ll i = 0;
        while (i < n && freq[s[i]] >= k) i++;
        if (i == n) return n;
        ll l = longestSubstring(s.substr(0, i), k);
        while (i < n && freq[s[i]] < k) i++;
        ll r = (i < n) ? longestSubstring(s.substr(i), k) : 0;
        return max(l, r);
    }
};