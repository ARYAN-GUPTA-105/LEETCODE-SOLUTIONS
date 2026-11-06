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
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& q) {
        sort(logs.begin(), logs.end(),[](auto& a, auto &b){return a[1] < b[1];});
        vector<pair<int, int>> queries;
        f(i, 0, q.size()) queries.pb({q[i], i});
        sort(queries.begin(), queries.end());
        vi cnt(n + 1, 0), ans(q.size());
        int l = 0, r = 0, curr = 0;
        for (auto [time, idx] : queries) {
            while (r < logs.size() && logs[r][1] <= time) {
                int id = logs[r][0];
                if (cnt[id] == 0) curr++;
                cnt[id]++;
                r++;
            }
            while (l < r && logs[l][1] < time - x) {
                int id = logs[l][0];
                cnt[id]--;
                if (cnt[id] == 0) curr--;
                l++;
            }
            ans[idx] = n - curr;
        }
        return ans;
    }
};
