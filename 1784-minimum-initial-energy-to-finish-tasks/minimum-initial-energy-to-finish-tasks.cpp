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
    int minimumEffort(vector<vector<int>>& tasks) {
        int ans = 0;
        for (auto& it : tasks)
            it[0] = it[1] - it[0];
        sort(tasks.begin(), tasks.end());
        for (auto& it : tasks)
            ans = max(ans + it[1] - it[0], it[1]);
        return ans;
    }
};