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
    bool isRectangleCover(vector<vector<int>>& rec) {
        map<pair<ll,ll>,ll> mk;
        for(vi& x : rec){
            mk[{x[0],x[1]}]++;
            mk[{x[0],x[3]}]--;
            mk[{x[2],x[1]}]--;
            mk[{x[2],x[3]}]++;
        }
        ll n = 0;
        for(auto i = mk.begin();i != mk.end();i++){
            if(i->second != 0){
                if(abs(i->second) != 1) return false;
                n++;
            }
        }
        return n == 4;
    }
};