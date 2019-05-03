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

const int N = 35;
const int T = 305;

int t1, t2, n, m[N], dp[N][T], a[N][T], b[N][T];

int solve(int indx, int rem) {
    if (indx == n) {
        if (rem)
            return MOD;
        return 0;
    }
    int& ret = dp[indx][rem];
    if (~ret) return ret;
    ret = MOD;
    for (int i = 0; i <= min(rem, m[indx]); ++i) {
        ret = min(ret, solve(indx + 1, rem - i) + a[indx][i] + b[indx][m[indx] - i]);
    }
    return ret;
}

void build(int indx, int rem, bool flag = false) {
    if (indx == n) return;
    int& ret = dp[indx][rem];
    for (int i = 0; i <= min(rem, m[indx]); ++i) {
        if (ret == solve(indx + 1, rem - i) + a[indx][i] + b[indx][m[indx] - i]) {
            if (flag) cout << ' ';
            cout << i;
            build(indx + 1, rem - i, true);
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    bool newline = false;
    while (cin >> t1 >> t2 && t1 + t2 != 0) {
        if (newline) cout << endl;
        newline = true;
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < n; ++i) {
            cin >> m[i];
            for (int j = 1; j <= m[i]; ++j) {
                cin >> a[i][j];
            }
            for (int j = 1; j <= m[i]; ++j) {
                cin >> b[i][j];
            }
        }
        cout << solve(0, t1) << endl;
        build(0, t1);
        cout << endl;
    }
}
