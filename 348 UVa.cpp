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

ll n, r[N], c[N], dp[N][N];

ll solve(int i, int j) {
    if (i == j) return 0;
    ll& ret = dp[i][j];
    if (~ret) return ret;
    ret = INF;
    for (int x = i; x < j; ++x) 
        ret = min(ret, solve(i, x) + solve(x + 1, j) + r[i] * c[x] * c[j]);
    return ret;
}

void build(int i, int j) {
    if (i == j) {
        cout << "A" << i + 1;
        return;
    }
    ll& ret = dp[i][j];
    for (int x = i; x < j; ++x) {
        if (ret == solve(i, x) + solve(x + 1, j) + r[i] * c[x] * c[j]) {
            cout << "(";
            build(i, x);
            cout << " x ";
            build(x + 1, j);
            cout << ")";
            return;
        }
    }
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int T = 1;;
    while (cin >> n && n) {
        for (int i = 0; i < n; ++i)
            cin >> r[i] >> c[i];

        memset(dp, -1, sizeof(dp));
        cout << "Case " << T++ << ": ";
        solve(0, n - 1);
        build(0, n - 1);
        cout << endl;
    }
}
