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

const int N = 205;

int n, m, dp[N][N];
string s, t;

int solve(int i, int j) {
    if (i == n || j == m)
        return 0;

    int& ret = dp[i][j];

    if (~ret) 
        return ret;

    ret = 0;

    if (s[i] == t[j])
        ret = solve(i + 1, j + 1) + 1;
    else 
        ret = max(solve(i + 1, j), solve(i, j + 1));
   
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int Case = 0;
    while (true) {
        getline(cin, s);
        if (s == "#") break;
        getline(cin, t);
        ++Case;
        n = (int) s.size();
        m = (int) t.size();
        memset(dp, -1, sizeof(dp));
        cout << "Case #" << Case << ": you can visit at most " << solve(0, 0) << " cities." << endl;
    }
}
