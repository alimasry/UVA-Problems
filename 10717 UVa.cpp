#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl '\n'

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 55;

ll n, t, a[N];

ll lcm(ll x, ll y) {
    return x / __gcd(x, y) * y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> t && n) {
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int x = 0; x < t; ++x) {
            ll minn = 0, maxx = LLONG_MAX;
            int b; cin >> b;
            for (int i = 0; i < n; ++i) {
                for (int j = i + 1; j < n; ++j) {
                    for (int k = j + 1; k < n; ++k) {
                        for (int l = k + 1; l < n; ++l) {
                            ll v = lcm(a[i], a[j]);
                            v = lcm(v, a[k]);
                            v = lcm(v, a[l]);
                            minn = max(minn, b - (b % v));
                            if (b % v)
                                maxx = min(maxx, b - (b % v) + v);
                            else
                                maxx = b;
                        }
                    }
                }
            }
            cout << minn << ' ' << maxx << endl;
        }
    }
}
