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

const int N = 1e4 + 5;
const int K = 105;

ll t, n, k, a[N], dp[N][K];

ll solve(int i, int rem) {
    if (i == n) return rem;
    ll& ret = dp[i][rem];
    if (~ret) return ret;
    ret = min(solve(i + 1, ((rem + a[i]) % k + k) % k), solve(i + 1, ((rem - a[i]) % k + k) % k));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        ll calc = solve(0, 0);
        if (calc) {
            cout << "Not divisible" << endl;
        } else {
            cout << "Divisible" << endl;
        }
    }
}
