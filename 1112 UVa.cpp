#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define endl "\n"

const ll INF = 1e15;
const int MOD = 1e9 + 7;
const double EPS = 1e-9;
const double PI = acos(-1.0);

const int N = 105;

ll t, n, m, T, E;

struct edge {
    ll to, cost;
    bool operator< (const edge& other) const {
        return cost > other.cost; 
    }
};

ll dist[N];
vector<edge> G[N];

void dijkstra(int src) {
    memset(dist, 0x7F, sizeof(dist));
    dist[src] = 0;
    priority_queue<edge> minn;
    minn.push({src, 0});
    while (!minn.empty()) {
        auto r = minn.top();
        minn.pop();
        ll u = r.to, cost = r.cost;

        if (dist[u] < cost) continue;

        for (edge& e : G[u]) {
            ll to = e.to, c = e.cost;
            if (dist[to] > dist[u] + c) {
                dist[to] = dist[u] + c;
                minn.push({to, dist[to]});
            }
        }
    }
}

void clear() {
    for (int i = 0; i < n; ++i) G[i].clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        cin >> n >> E >> T >> m;
        clear();
        for (int i = 0; i < m; ++i) {
            int u, v, c; cin >> u >> v >> c;
            --u, --v;
            G[v].push_back({u, c});
        }

        dijkstra(E - 1);

        ll ans = 0;
        for (int i = 0; i < n; ++i) 
            if (dist[i] <= T) ++ans;

        cout << ans << endl;
        if (t) cout << endl;
    }
}
