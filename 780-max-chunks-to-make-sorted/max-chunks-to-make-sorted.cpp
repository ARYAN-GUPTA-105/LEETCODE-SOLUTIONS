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
    int maxChunksToSorted(vector<int>& arr) {
        ll mx = 0, cnk = 0;
        f(i,0,arr.size()){
            mx = max(mx,(ll)arr[i]);
            if(mx == i) cnk++;
        }
        return cnk;
    }
};