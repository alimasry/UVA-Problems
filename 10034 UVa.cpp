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

pair<double, double> a[N];
ll t, n, p[N], s[N];

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

struct edge {
    ll x, y;
    double dist;
    bool operator< (const edge& other) const {
        return dist < other.dist;
    }
};

vector<pair<int, double>> G[N];
vector<edge> edges;

void mst() {
    sort(edges.begin(), edges.end());
    for (int i = 0; i <= n; ++i) p[i] = i, s[i] = 1;

    for (auto& e : edges) {
        if (root(e.x) != root(e.y)) {
            merge(e.x, e.y);
            G[e.x].emplace_back(e.y, e.dist);
            G[e.y].emplace_back(e.x, e.dist);
        }
    }
}

double dist(int x, int y) {
    double dx = a[x].first - a[y].first, dy = a[x].second - a[y].second;
    return sqrt(dx * dx + dy * dy);
}

ll vis[N], vid;

double dfs(ll u) {
    vis[u] = vid;
    double ret = 0;
    for (auto& to : G[u])
        if (vis[to.first] != vid)
            ret += dfs(to.first) + to.second;
    return ret;
}

void clear() {
    ++vid;
    for (int i = 0; i < n; ++i) G[i].clear();
    edges.clear();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    cin >> t;

    while (t--) {
        if (vid) cout << endl;
        cin >> n;
        clear();
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first >> a[i].second;
            for (int j = 0; j < i; ++j) 
                edges.push_back({i, j, dist(i, j)});
        }
        mst();
        cout << fixed << setprecision(2) << dfs(0) << endl;
    }
}
