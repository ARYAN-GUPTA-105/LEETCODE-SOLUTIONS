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
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> busy, idle;
        f(i,0,servers.size()) idle.push({servers[i],i});
        ll t = 0; vi ans(tasks.size());
        auto helper = [&](ll time){
            while(!busy.empty() && busy.top().first <= time){
                ll idx = busy.top().second; busy.pop(); idle.push({servers[idx],idx});
            }
        };
        f(i,0,tasks.size()){
            t = max(t,(ll)i); helper(t); if(idle.empty()) t = busy.top().first, helper(t);
            ll idx = idle.top().second; idle.pop(); ans[i] = idx; busy.push({t + tasks[i], idx});
        }
        return ans;
    }
};