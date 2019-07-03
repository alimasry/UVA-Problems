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

const int N = 105;
const int M = 1e4 + 5;

pll p[N];
ll m, n, dp[N][M + 300];

ll solve(int i, int cost) {
    if (i == n) return 0;
    ll& ret = dp[i][cost];
    if (~ret) return ret;
    ret = solve(i + 1, cost);
    if (cost + p[i].first - (cost + p[i].first > 2000) * 200 <= m)
        ret = max(ret, solve(i + 1, cost + p[i].first) + p[i].second);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> m >> n) {
        memset(dp, -1, sizeof(dp));
        for (int i = 0; i < n; ++i)
            cin >> p[i].first >> p[i].second;
        sort(p, p + n);
        cout << solve(0, 0) << endl;
    }
}
