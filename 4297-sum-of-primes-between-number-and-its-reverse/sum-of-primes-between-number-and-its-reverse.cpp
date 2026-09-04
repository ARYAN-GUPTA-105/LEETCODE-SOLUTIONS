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
    bool helper(int n){
        for(int i = 2;i*i<=n;i++){
            if(n % i == 0) return false;
        }
        return true;
    }
    int sumOfPrimesInRange(int n) {
        int rev = 0;
        int curr = n;
        while(curr){
            rev = rev * 10 + (curr % 10);
            curr /= 10;
        }
        ll ans = 0;
        if(rev > n){
           f(i,n,rev+1) if(i != 1 && helper(i)) ans+=i;
        }
        else{
            f(i,rev,n+1) if(i != 1 && helper(i)) ans+=i;
        }
        return ans;
    }
};