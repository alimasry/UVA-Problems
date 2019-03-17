// UVa 539
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

const int N = 30;

ll n, m;
vector<ll> G[N];
set<pll> vis;

ll solve(ll u) {
    ll ret = 0;
    for (auto to : G[u]) {
        if (vis.insert({min(to, u), max(to, u)}).second) {
            ret = max(ret, solve(to) + 1);
            vis.erase({min(to, u), max(to, u)});
        }
    }
    return ret;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> m && n) {
        for (int i = 0; i < m; ++i) {
            int u, v; cin >> u >> v;
            G[u].push_back(v);
            G[v].push_back(u);
        }

        ll ans = 0;
        for (int i = 0; i < n; ++i) {
            ans = max(ans, solve(i));
            vis.clear();
        }
        
        cout << ans << endl;

        for (int i = 0; i < n; ++i) {
            G[i].clear();
        }
        vis.clear();
    }
}


