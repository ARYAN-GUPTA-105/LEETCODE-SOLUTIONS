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
    int maxDiff(int num) {
        ll a = 0;
        ll b = 0;
        string n1 = to_string(num);
        string n2 = to_string(num);
        ll i = 0;
        while (i < n1.length() && n1[i] == '9')
            i++;
        char ch = n1[i];
        while (i < n1.length()) {
            if (n1[i] == ch)
                n1[i] = '9';
            i++;
        }
        i = 0;
        while (i < n2.length() && (n2[i] == '1' || n2[i] == '0'))
            i++;
        if (i == 0) {
            ch = n2[i];
            while (i < n2.length()) {
                if (n2[i] == ch)
                    n2[i] = '1';
                i++;
            }
        }
        else{
            ch = n2[i];
            while (i < n2.length()) {
                if (n2[i] == ch)
                    n2[i] = '0';
                i++;
            }
        }
        a = stoi(n1);
        b = stoi(n2);
        return a - b;
    }
};