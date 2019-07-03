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

const int N = 2e5 + 5;

ll t, n, m, s, d;

struct edge {
    ll to, cost;
    bool operator< (const edge& other) const {
        return cost > other.cost; 
    }
};

ll dist[N];
vector<edge> G[N];

void dijkstra(int src) {
    fill (dist, dist + n, INF);
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

    for (int T = 1; T <= t; ++T) {
        cin >> n >> m >> s >> d;
        clear();
        for (int i = 0; i < m; ++i) {
            ll u, v, w; cin >> u >> v >> w;
            G[u].push_back({v, w});
            G[v].push_back({u, w});
        }
        dijkstra(s);
        cout << "Case #" << T << ": ";
        if (dist[d] == INF)
            cout << "unreachable" << endl;
        else cout << dist[d] << endl;
    }
}
