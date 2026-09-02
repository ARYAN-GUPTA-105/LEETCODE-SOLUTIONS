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
class Solution {
public:
    queue<int> q;
    bool helper(vi& nums,vvii& adj, int bit){
        int n = nums.size(), node = -1;
        f(i,0,n){
            if(bit & (1 << i)){
                bit ^= (1 << i);
                node = i;
                break;
            }
        }
        q.push(node);
        int scr = 0;
        while(!q.empty()){
            auto x = q.front();
            q.pop();
            scr += nums[x];
            for(auto &y : adj[x]){
                if(bit & (1<<y)){
                    bit ^= (1 << y);
                    q.push(y);
                }
            }
        }
        return (bit == 0 && (scr % 2 == 0));
    }
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vvii adj(n);
        for(auto& x : edges){
            adj[x[0]].pb(x[1]);
            adj[x[1]].pb(x[0]);
        }
        int ans = 0;
        f(i,1,(1<<n)){
            if(helper(nums,adj,i)) ans++;
        }
        return ans;
    }
};