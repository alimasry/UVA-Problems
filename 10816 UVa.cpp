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

const int N = 105;

ll n, e, s, t;

struct edge {
    ll to, cost, degree;
    bool operator< (const edge& other) const {
        return cost > other.cost; 
    }
};

ll dist[N], p[N];
vector<edge> G[N];

void dijkstra(int src, ll degree) {
    fill(dist, dist + n, INF);
    memset(p, -1, sizeof(p));
    dist[src] = 0;
    priority_queue<edge> minn;
    minn.push({src, 0, 0});
    while (!minn.empty()) {
        auto r = minn.top();
        minn.pop();
        ll u = r.to, cost = r.cost;

        if (dist[u] < cost) continue;

        for (edge& e : G[u]) {
            ll to = e.to, c = e.cost;
            double d = e.degree;
            if (d <= degree && dist[to] > dist[u] + c) {
                p[to] = u;
                dist[to] = dist[u] + c;
                minn.push({to, dist[to]});
            }
        }
    }
}

void clear() {
    for (int i = 0; i < n; ++i) G[i].clear();
}

ll val(const string& s) {
    ll ret = 0;
    for (char c : s) {
        if (c == '.') break;
        ret = ret * 10 + (c - '0');
    }
    ret = ret * 10 + (s.back() - '0');
    return ret;
}

void print(ll u) {
    if (u == -1) return;
    print(p[u]);
    cout << u + 1;
    if (u != t) cout << ' ';
}

bool valid(ll mid) {
    dijkstra(s, mid);
    return dist[t] != INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    while (cin >> n >> e >> s >> t) {
        clear();
        --t, --s;
        for (int i = 0; i < e; ++i) {
            ll x, y; cin >> x >> y;
            string d, r; cin >> r >> d;
            --x, --y;
            G[x].push_back({y, val(d), val(r)});
            G[y].push_back({x, val(d), val(r)});
        }

        ll l = 0, r = MOD;
        while (l < r) {
            ll mid = l + ((r - l) >> 1);
            if (valid(mid))
                r = mid;
            else
                l = mid + 1;
        }

        dijkstra(s, l);
        print(t);
        cout << endl << fixed << setprecision(1) << dist[t] / 10.0 << ' ' <<  l / 10.0 << endl;
    }
}
