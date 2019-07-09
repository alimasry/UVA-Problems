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

const int N = 15;
const int M = 105;

ll t, n, m, L[N][M], dp[N][M];

ll solve(int i, int t) {
    if (t > m) return -INF;
    if (i == n) return 0;
    ll& ret = dp[i][t];
    if (~ret) return ret;
    ret = -INF;
    for (int j = 0; j < m; ++j)
        if (L[i][j] >= 5) 
            ret = max(ret, solve(i + 1, t + j + 1) + L[i][j]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n >> m;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> L[i][j];

        memset(dp, -1, sizeof(dp));
        ll calc = solve(0, 0);
        if (calc < n * 5) 
            cout << "Peter, you shouldn't have played billiard that much." << endl;
        else
            cout << "Maximal possible average mark - " << fixed <<  setprecision(2) << calc * 1.0 / (double) n + 0.0001 << "." << endl;
    }
}
