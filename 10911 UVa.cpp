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

const int N = 17;

ll n, x[N], y[N];
double dp[1 << N];

double dist(int i, int j) {
    double dx = x[i] - x[j], dy = y[i] - y[j];
    return sqrt(dx * dx + dy * dy);
}

double solve(int mask, int cnt = 0) { 
    if (cnt == n) return 0;
    double& ret = dp[mask];
    if (ret == ret) return ret;
    ret = INF;
    for (int i = 0; i < 2 * n; ++i)
        if ((mask & (1 << i)) == 0)
            for (int j = 0; j < 2 * n; ++j)
                if (i != j && (mask & (1 << j)) == 0)
                    ret = min(ret, solve(mask | (1 << i) | (1 << j), cnt + 1) + dist(i, j));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;
    while (cin >> n && n) {

        for (int i = 0; i < 2 * n; ++i) {
            string s; cin >> s;
            cin >> x[i] >> y[i];
        }

        memset(dp, -1, sizeof(dp));
        cout << "Case " << T++ << ": ";
        cout << fixed << setprecision(2) << solve(0) << endl;
    }
}
