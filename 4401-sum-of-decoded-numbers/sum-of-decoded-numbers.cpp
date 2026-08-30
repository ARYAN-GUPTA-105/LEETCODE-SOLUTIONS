#define ll long long
class Solution {
public:
    ll modpow(ll x, ll y, ll mod) {
        ll ans = 1;
        while (y > 0) {
            if (y & 1)
                ans = ans * x % mod;
            x = x * x % mod;
            y >>= 1;
        }
        return ans;
    }
    int sumDecoded(vector<ll>& nums) {
        ll ans = 0;
        ll mod = 1e9 + 7;
        for (ll x : nums) {
            ll wi = x % 10;
            ll di = x / 10;
            vector<ll> v;
            while (di > 0)
                v.push_back(di % 10), di /= 10;
            ll n = v.size();
            ll xi = 0;
            ll yi = 0;
            for (ll i = 0; i < wi; i++) {
                xi = xi * 10 + v[v.size() - i - 1];
            }
            for (ll i = wi; i < v.size(); i++) {
                yi = yi * 10 + v[v.size() - i - 1];
            }
            ans = (ans + modpow(xi, yi, mod)) % mod;
        }
        return (int)ans;
    }
};