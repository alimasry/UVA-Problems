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

const int L = 1005;
const int N = 55;

int l, n, a[N], dp[N][N];

int solve(int i, int j) {
    if (i + 1 == j) return 0;
    int& ret = dp[i][j];
    if (~ret) return ret;
    ret = MOD;
    for (int k = i + 1; k < j; ++k) 
        ret = min(ret, solve(i, k) + solve(k, j) + a[j] - a[i]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> l && l) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        a[n + 1] = l;
        sort (a, a + n + 2);
        cout << "The minimum cutting is " << solve(0, n + 1) << '.' << endl;
    }
}

