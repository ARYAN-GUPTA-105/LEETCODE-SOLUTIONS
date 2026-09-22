// ye question ko krne me tantra mantra ka istemal hua h kyunki iss question ne
// meri phaardi thi in simple words i was not able to solve this question
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
    static const ll mxsz = 1 << 18;
    ll prodarr[mxsz], freqarr[mxsz * 5], nmod[5][5];
    vector<int> resultArray(vector<int>& nums, int k,
                            vector<vector<int>>& queries) {
        ll n = nums.size(), size = 1;
        while (size < n)
            size <<= 1;
        f(a, 0, k) { f(b, 0, k) nmod[a][b] = (a * b) % k; }
        auto setlf = [&](ll pos, ll val) {
            ll r = val % k;
            prodarr[pos] = r;
            ll base = pos * 5;
            f(i, 0, k) freqarr[base + i] = 0;
            freqarr[base + r] = 1;
        };
        f(i, 0, n) setlf(size + i, nums[i]);
        auto cbinto = [&](ll node, ll l, ll r) {
            ll lp = prodarr[l], rp = prodarr[r];
            prodarr[node] = nmod[lp][rp];
            ll nb = node * 5, lb = l * 5, rb = r * 5;
            f(i, 0, k) freqarr[nb + i] = freqarr[lb + i];
            f(i, 0, k) {
                ll c = freqarr[rb + i];
                if (c)
                    freqarr[nb + nmod[lp][i]] += c;
            }
        };
        rf(i, size - 1, 1) cbinto(i, 2 * i, 2 * i + 1);
        auto update = [&](ll idx, ll val) {
            ll pos = size + idx;
            setlf(pos, val);
            pos >>= 1;
            while (pos >= 1) {
                cbinto(pos, pos << 1, pos << 1 | 1);
                pos >>= 1;
            }
        };
        ll lf[5], rf[5];
        auto query = [&](ll l, ll r, ll x) -> ll {
            ll lp = 1 % k, rp = 1 % k;
            f(i, 0, k) lf[i] = 0, rf[i] = 0;
            l += size;
            r += size;
            while (l < r) {
                if (l & 1) {
                    ll base = l * 5;
                    f(i, 0, k) {
                        ll c = freqarr[base + i];
                        if (c)
                            lf[nmod[lp][i]] += c;
                    }
                    lp = nmod[lp][prodarr[l]];
                    l++;
                }
                if (r & 1) {
                    r--;
                    ll base = r * 5, pr = prodarr[r];
                    ll tmp[5];
                    f(i, 0, k) tmp[i] = freqarr[base + i];
                    f(i, 0, k) {
                        ll c = rf[i];
                        if (c)
                            tmp[nmod[pr][i]] += c;
                    }
                    f(i, 0, k) rf[i] = tmp[i];
                    rp = nmod[pr][rp];
                }
                l >>= 1, r >>= 1;
            }
            ll res[5] = {0, 0, 0, 0, 0};
            f(i, 0, k) res[i] = lf[i];
            f(i, 0, k) {
                ll c = rf[i];
                if (c)
                    res[nmod[lp][i]] += c;
            }
            return res[x];
        };
        vi ans;
        ans.reserve(queries.size());
        for (auto& q : queries) {
            update(q[0], q[1]);
            ans.pb(query(q[2], n, q[3]));
        }
        return ans;
    }
};