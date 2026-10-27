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
    int longestMountain(vector<int>& arr) {
        ll n = arr.size(), ans = 0, u = 0, d = 0;
        f(i,1,n){
            if((d && arr[i-1] < arr[i]) || arr[i-1] == arr[i]) u = d = 0;
            u += arr[i-1] < arr[i], d += arr[i-1] > arr[i];
            if(u && d) ans = max(ans,u+d+1);
        }
        return ans;
    }
};