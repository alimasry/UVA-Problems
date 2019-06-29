#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-7;
const double PI = acos(-1.0);

const int N = 205;
const int M = 15;
const int D = 25;

ll n, q, d, m, a[N], dp[N][M][D];

ll solve(ll i, ll cnt, ll sum) {
    if (cnt > m) return 0;
    if (i == n) return (cnt == m && sum == 0);
    ll& ret = dp[i][cnt][sum];
    if (~ret) return ret;
    ret = solve(i + 1, cnt, sum) + solve(i + 1, cnt + 1, ((sum + (a[i] % d)) % d + d) % d);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int T = 1;
    while (cin >> n >> q && (n || q)) {
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << "SET " << T++ << ":" << endl;
        for (int Q = 1; Q <= q; ++Q) {
            memset(dp, -1, sizeof(dp));
            cin >> d >> m;
            cout << "QUERY " << Q << ": " << solve(0, 0, 0) << endl;
        }
    }
}
