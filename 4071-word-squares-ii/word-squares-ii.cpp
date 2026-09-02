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
    vector<vector<string>> ans;
    void helper(vector<string>& words,vector<string>& w,us<int>&st){
        if(w.size() == 4){
            if(w[0][0] == w[1][0] && w[0][3] == w[2][0] && w[3][0] == w[1][3] && w[3][3] == w[2][3]) ans.pb(w);
            return;
        }
        f(i,0,words.size()){
            if(!st.count(i)){
                w.pb(words[i]);
                st.insert(i);
                helper(words,w,st);
                w.pop_back();
                st.erase(i);
            }
        }
    }
    vector<vector<string>> wordSquares(vector<string>& words) {
        us<int> st;
        vector<string> w;
        f(i,0,words.size()){
            st.insert(i);
            w.pb(words[i]);
            helper(words,w,st);
            st.erase(i);
            w.pop_back();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};