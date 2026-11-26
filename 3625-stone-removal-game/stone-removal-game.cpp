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
    bool canAliceWin(int n) {
        ll i = 10;
        while(true){
            if(n >= i) n -= i;
            else return false;
            i--;
            if(n >= i) n -= i;
            else return true;
            i--;
        }
        return true;
    }
};