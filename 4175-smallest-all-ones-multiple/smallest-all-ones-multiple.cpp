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
    int minAllOneMultiple(int k) {
        if(!(k % 2) || !(k % 5)) return -1;
        ll bc = 0;
        f(i,1,k+1){
            bc = (bc * 10 + 1) % k;
            if(!bc) return i;
        }
        return -1;
    }
};