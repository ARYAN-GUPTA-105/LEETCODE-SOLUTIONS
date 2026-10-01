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
    vector<bool> vec;
    void helper(ll idx, vector<vector<int>>& rooms) {
        vec[idx] = true;
        f(i, 0, rooms[idx].size()) {
            if (!vec[rooms[idx][i]])
                helper(rooms[idx][i], rooms);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        ll n = rooms.size();
        vec.resize(n, false);
        helper(0, rooms);
        f(i, 0, n) if (vec[i] == false) return false;
        return true;
    }
};