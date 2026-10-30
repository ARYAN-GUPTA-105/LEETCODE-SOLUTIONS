//tantarr thoda sa
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
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<ll,ll>>> gr(n);
        for(auto& e : edges) gr[e[0]].emplace_back(e[1],e[2]);
        vvii dist(n,vi(k+1,1e9));
        priority_queue<tuple<ll,ll,ll>,vector<tuple<ll,ll,ll>>, greater<>> pq;
        dist[0][1] = 0;pq.emplace(0,0,1);
        while(!pq.empty()){
            auto [d,u,cnt] = pq.top();pq.pop();if(d > dist[u][cnt]) continue;
            if(u == n - 1) return d;
            for(auto [v,w] : gr[u]){
                ll ncnt = (labels[u] == labels[v]) ? cnt+1 : 1;
                if(ncnt > k) continue;
                if(d + w < dist[v][ncnt]) dist[v][ncnt] = d + w, pq.emplace(dist[v][ncnt],v,ncnt);
            } 
        }
        return -1;
    }
};