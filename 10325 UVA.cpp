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

const int N = 20;

ll n, m, a[N];

ll lcm(ll a, ll b) {
    return a / __gcd(a, b) * b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> m) {
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        ll ans = 0;
        for (int mask = 0; mask < (1 << m); ++mask) {
            ll d = 1, sign = 1;
            for (int i = 0; i < m; ++i) {
                if (mask & (1 << i)) {
                    d = lcm(d, a[i]);
                    sign = -sign;
                }
            }
            ans += sign * (n / d);
        }
        cout << ans << endl;
    }
}
