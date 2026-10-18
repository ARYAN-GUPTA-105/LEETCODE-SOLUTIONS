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
    long long subArrayRanges(vector<int>& nums) {
        ll m, n, s = nums.size(), ans = 0;
        stack<ll> st;
        f(i, 0, s + 1) {
            while (!st.empty() && (i == s || nums[st.top()] < nums[i])) {
                m = st.top(); st.pop();
                if (!st.empty()) n = st.top(); else n = -1;
                ans += (ll)nums[m] * (i - m) * (m - n);
            }
            st.push(i);
        }
        stack<ll> st2;
        f(i, 0, s + 1) {
            while (!st2.empty() && (i == s || nums[st2.top()] > nums[i])) {
                m = st2.top(); st2.pop();
                if (!st2.empty()) n = st2.top(); else n = -1;
                ans -= (ll)nums[m] * (i - m) * (m - n);
            }
            st2.push(i);
        }
        return ans;
    }
};