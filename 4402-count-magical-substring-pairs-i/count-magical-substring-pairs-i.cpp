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
    int countMagicalPairs(string s) {
        ll n = s.length(), ans = 0;
        f(j,0,n-1){
            us<char> st;
            vll cnt(27,0);
            rf(i,j,0) st.insert(s[i]), cnt[st.size()]++;
            st.clear();
            f(i,j+1,n) st.insert(s[i]), ans += cnt[st.size()];
        }
        return ans;
    }
};