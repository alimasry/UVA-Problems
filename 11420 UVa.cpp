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

const int N = 70;

ll n, s, dp[N][N][2]; 

ll solve(int i, int j, bool lst) {
    if (i == n) return j == s;
    ll& ret = dp[i][j][lst];
    if (~ret) return ret;
    ret = solve(i + 1, j, 0);
    if (lst)
        ret += solve(i + 1, j + 1, 1);
    else 
        ret += solve(i + 1, j, 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> s) {
        if (n < 0 && s < 0) return 0;
        memset(dp, -1, sizeof(dp));
        cout << solve(0, 0, 1) << endl;
    }
}
