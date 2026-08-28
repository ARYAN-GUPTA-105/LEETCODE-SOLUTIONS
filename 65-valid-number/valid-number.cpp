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
    bool isNumber(string s) {
        int n = s.length();
        int cnte = 0, cntd = 0, cntn = 0, cntae = 0;
        f(i,0,n){
            if(s[i] == '.') cntd++;
            if(s[i] == 'e' || s[i] == 'E') cnte++;
            if(isdigit(s[i])){
                if(cnte) cntae++;
                else cntn++;
            }
            if((s[i] == '+' || s[i] == '-') && i != 0 && (s[i - 1] != 'e' && s[i-1] != 'E')) return false;
            else if(isalpha(s[i]) && (s[i] != 'e' && s[i] != 'E')) return false;
            else if(cntd > 1 || cnte > 1) return false;
            else if(s[i] == '.' && cnte) return false;
            else if((i == 0 || i == n - 1) && (s[i] == 'e' || s[i] == 'E')) return false;
            else if(i == 0 && i == n-1 && s[i] == '.') return false;
            else if((s[i] == 'e' || s[i] == '   E') && !cntn) return false;
        }
        if((cnte && !cntae) || !cntn) return false;
        return true;
    }
};