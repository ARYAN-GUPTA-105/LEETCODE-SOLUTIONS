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
    int totalNumbers(vector<int>& digits) {
        us<int> st;
        ll n = digits.size();
        ll ans = 0;
        f(i,0,n){
            if(digits[i] == 0) continue;
            ll curr = digits[i];
            f(j,0,n){
                if(j == i) continue;
                ll curr2 = curr * 10 + digits[j];
                f(k,0,n){
                    if(k == j || k == i) continue;
                    ll curr3 = curr2 * 10 + digits[k];
                    if(curr3 % 2 == 0 && !st.count(curr3)) ans++, st.insert(curr3);
                }
            }
        }
        return ans;
    }
};