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

const int N = 105;
const int M = 505;

ll n, m, a[N], dp[N][2 * M * N]; 

ll solve(int i, int diff) {
    if (i == m) 
        return llabs(diff);
    ll& ret = dp[i][diff + M * N];
    if (~ret) return ret;
    ret = solve(i + 1, diff + a[i]);
    ret = min(ret, solve(i + 1, diff - a[i]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> n;
    while (n--) {
        cin >> m;
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0) << endl;
    }
}
