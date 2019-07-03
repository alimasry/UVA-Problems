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

const int N = 35;
const int T = 1005;

pll v[N];
ll t, w, n, dp[N][T];

ll solve(int i, ll rem) {
    if (rem < 0) return -INF;
    if (i == n) return 0;
    ll& ret = dp[i][rem];
    if (~ret) return ret;
    ret = solve(i + 1, rem);
    if (rem >= v[i].first * 3 * w)
        ret = max(ret, solve(i + 1, rem - v[i].first * 3 * w) + v[i].second);
    return ret;
}

vector<int> ans;
void build(int i, ll rem) {
    if (i == n) return;
    ll& ret = dp[i][rem];
    if (rem >= v[i].first * 3 * w && ret == solve(i + 1, rem - v[i].first * 3 * w) + v[i].second) {
        ans.push_back(i);
        build(i + 1, rem - v[i].first * 3 * w);
    } else build(i + 1, rem);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    bool first = true;
    while (cin >> t >> w) {
        if (first) first = false;
        else cout << endl;

        memset(dp, -1, sizeof(dp));

        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> v[i].first >> v[i].second;

        cout << solve(0, t) << endl;
        build(0, t);

        cout << (int) ans.size() << endl;
        for (int i : ans)
            cout << v[i].first << ' ' << v[i].second << endl;

        ans.clear();
    }
}
