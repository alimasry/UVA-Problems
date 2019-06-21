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

const int N = 205;

pll a[N];
ll n, p[N], s[N];

struct edge {
    ll x, y, dist;
    bool operator< (const edge& other) const {
        return dist < other.dist;
    }
};

vector<pll> G[N];
vector<edge> edges;


ll root(ll x) {
    if (x == p[x]) return x;
    return p[x] = root(p[x]);
}

void merge(ll x, ll y) {
    x = root(x), y = root(y);
    if (x != y) {
        if (s[x] > s[y]) swap(x, y);
        p[x] = y;
        s[y] += s[x];
    }
}

ll vis[N], vid;

void dfs(ll u, ll maxx = 0) {
    if (u == 1) cout << fixed << setprecision(3) << sqrt(maxx) << endl << endl;
    vis[u] = vid;
    for (auto& to : G[u]) {
        if (vis[to.first] != vid) dfs(to.first, max(maxx, to.second));
    }
}

ll dist(pll x, pll y) {
    ll dx = x.first - y.first, dy = x.second - y.second;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    ll T = 1;
    while (cin >> n && n) {
        ++vid;
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            s[i] = 1, p[i] = i;
            for (int j = 0; j < i; ++j) {
                edges.push_back({i, j, dist(a[i], a[j])});
            }
        }

        sort(edges.begin(), edges.end());
        for (auto& x : edges) {
            if (root(x.x) != root(x.y)) {
                merge(x.x, x.y);
                G[x.x].emplace_back(x.y, x.dist);
                G[x.y].emplace_back(x.x, x.dist);
            }
        }

        cout << "Scenario #" << T++ << endl;
        cout << "Frog Distance = ";
        dfs(0);
        for (int i = 0; i < n; ++i) G[i].clear();
        edges.clear();
    }
    return 0;
}
