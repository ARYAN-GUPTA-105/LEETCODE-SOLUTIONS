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
    string sortVowels(string s) {
        um<char,int> mp;
        for(char c : s){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') mp[c]++;
        }
        vector<pair<char,int>> v;
        for(auto& x : mp) v.pb(x);
        sort(v.begin(),v.end(),[](auto &a,auto &b){
            return a.second<b.second;
        });
        stack<char> st;
        f(i,0,v.size()){
            while(v[i].second--) st.push(v[i].first);
        }
        f(i,0,s.size()){
            char c = s[i];
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                c = st.top();
                s[i] = c;
                st.pop();
            }
        }
        return s;
    }
};