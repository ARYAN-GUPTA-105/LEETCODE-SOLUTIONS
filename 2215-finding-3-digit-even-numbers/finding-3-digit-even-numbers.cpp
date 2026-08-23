#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

using vi = vector<int>;
using vll = vector<long long>;
using vvll = vector<vll>;
using vvii = vector<vector<int>>;
#define f(i, a, n) for (int i = a; i < n; i++)
#define rf(i, a, n) for (int i = a; i >= n; i--)
#define pb push_back
class Solution {
public:
    vi ans;
    unordered_set<int> st;
    void helper(vi& digits, int idx, int val,int idx2) {
        if (val >= 100 && val <= 999) {
            if (val % 2 == 0 && !st.count(val))
                ans.push_back(val), st.insert(val);
            return;
        }
        f(i, 0, digits.size()) {
            if (i == idx || i == idx2)
                continue;
            helper(digits, i, val * 10 + digits[i],idx);
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        f(i, 0, digits.size()) {
            if (digits[i] == 0)
                continue;
            helper(digits, i, digits[i],-1);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};